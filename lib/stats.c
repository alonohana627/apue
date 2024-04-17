#include <stats.h>
#include <stdio.h>
#include <pwd.h>
#include <shadow.h>
#include <sys/utsname.h>
#include <sys/resource.h>

inline long get_posix_version(void) {
    return sysconf(_SC_VERSION);
}

inline long get_xsi_version(void) {
    return sysconf(_SC_XOPEN_VERSION);
}

inline long get_openmax(void) {
    return sysconf(_SC_OPEN_MAX);
}

inline long get_maxargs(void) {
    return sysconf(_SC_ARG_MAX);
}

void pretty_stats_print(void) {
    printf("POSIX Version: %zu\n", get_posix_version());
    printf("XSI Version: %zu\n", get_xsi_version());
    printf("Maximum opened files: %zu\n", get_openmax());
    printf("Maximum arguments per `exec` function: %zu\n", get_maxargs());
}

void user_pwd_info(void) {
    struct passwd *ptr;
    uid_t uid;

    setpwent();
    uid = getuid();
    if ((ptr = getpwuid(uid)) == NULL) {
        return;
    }

    printf("Username: %s\n", ptr->pw_name);
    printf("User dir: %s\n", ptr->pw_dir);
    printf("Real Name: %s\n", ptr->pw_gecos);
    printf("Current Shell: %s\n", ptr->pw_shell);

    endpwent();
}

void user_shadow_info(void) {
    struct spwd *ptr;

    setspent();
    if ((ptr = getspent()) == NULL) {
        return;
    }

    printf("Login Name: %s\n", ptr->sp_namp);
    printf("Hashed Password: %s\n", ptr->sp_pwdp);

    endspent();
}

void system_info(void){
    struct utsname ver;

    if(uname(&ver) <0){
        return;
    }

    printf("Machine: %s\n", ver.machine);
    printf("Node name: %s\n", ver.nodename);
    printf("Release: %s\n", ver.release);
    printf("System Name: %s\n", ver.sysname);
    printf("version: %s\n", ver.version);
}

void _print_limit(char *name, int resource){
    struct rlimit rlptr;

    if(getrlimit(resource, &rlptr) < 0){
        return;
    }

    printf("%s max: %lu. %s cur: %lu\n", name, rlptr.rlim_max, name, rlptr.rlim_cur);
}

#define PRINT_LIMIT(name) do{_print_limit(#name, name);}while(0)

void process_resource_limits(void){
    PRINT_LIMIT(RLIMIT_CPU);
    PRINT_LIMIT(RLIMIT_FSIZE);
    PRINT_LIMIT(RLIMIT_DATA);
    PRINT_LIMIT(RLIMIT_STACK);
    PRINT_LIMIT(RLIMIT_CORE);
    PRINT_LIMIT(RLIMIT_RSS);
    PRINT_LIMIT(RLIMIT_NOFILE);
    PRINT_LIMIT(RLIMIT_OFILE);
    PRINT_LIMIT(RLIMIT_AS);
    PRINT_LIMIT(RLIMIT_NPROC);
    PRINT_LIMIT(RLIMIT_MEMLOCK);
    PRINT_LIMIT(RLIMIT_LOCKS);
    PRINT_LIMIT(RLIMIT_SIGPENDING);
    PRINT_LIMIT(RLIMIT_MSGQUEUE);
    PRINT_LIMIT(RLIMIT_NICE);
    PRINT_LIMIT(RLIMIT_RTPRIO);
    PRINT_LIMIT(RLIMIT_RTTIME);
    PRINT_LIMIT(RLIMIT_NLIMITS);
    PRINT_LIMIT(RLIM_NLIMITS);
}
