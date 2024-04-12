#include <ping.h>

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) sum += *buf++;
    if (len == 1) sum += *(unsigned char *) buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void ping(const char *destination) {
    int sock;
    struct sockaddr_in dest_addr;
    struct iphdr *ip_header;
    struct icmphdr *icmp_header;
    char packet[PACKET_SIZE];
    char buffer[PACKET_SIZE];
    ssize_t bytes_received;

    // Create raw socket
    sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Prepare destination address
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    inet_pton(AF_INET, destination, &dest_addr.sin_addr);

    // Prepare ICMP header
    icmp_header = (struct icmphdr *) packet;
    icmp_header->type = ICMP_ECHO_REQUEST;
    icmp_header->code = 0;
    icmp_header->checksum = 0;
    icmp_header->un.echo.id = getpid();
    icmp_header->un.echo.sequence = 0;
    icmp_header->checksum = checksum(icmp_header, sizeof(struct icmphdr));

    // Send the packet
    if (sendto(sock, packet, sizeof(struct icmphdr), 0, (struct sockaddr *) &dest_addr, sizeof(dest_addr)) <= 0) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

//    printf("Ping request sent to %s\n", destination);

    // Receive ICMP echo reply packet
    bytes_received = recv(sock, buffer, PACKET_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Extract IP header
    ip_header = (struct iphdr *) buffer;

    // Extract ICMP header
    icmp_header = (struct icmphdr *) (buffer + (ip_header->ihl * 4));

    // Check if the received packet is an ICMP echo reply
    if (icmp_header->type == ICMP_ECHO_REPLY) {
        printf("Ping reply received from %s\n", inet_ntoa(dest_addr.sin_addr));
    } else {
        printf("Unexpected response received\n");
    }

    close(sock);
}
