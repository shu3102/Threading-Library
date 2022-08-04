
#define RED "\033[1;31m"
#define RESET "\033[0m"

/**
 * @brief Macro for installing custom signal handlers for threads
 * 
 */
#define WRAP_SIGNALS(signum)          \
    signal(signum, TLIB_SIG_HANDLER); \
    sigemptyset(&base_mask);          \
    sigaddset(&base_mask, signum);    \
    sigprocmask(SIG_UNBLOCK, &base_mask, NULL);

/**
 * @brief Custom signal handler function
 * 
 * @param signum Signal Number
 */
void TLIB_SIG_HANDLER(int signum)
{
    printf(RED "Signal Dispatched\n" RESET);
    printf("Thread tid %ld handled signal\n", (long)gettid());
    fflush(stdout);
}