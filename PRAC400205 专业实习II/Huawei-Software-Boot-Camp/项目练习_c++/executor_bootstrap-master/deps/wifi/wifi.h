
#ifndef E4C061EA8E754A4993CFDE1363CD7138
#define E4C061EA8E754A4993CFDE1363CD7138

void send_json(const char *json);

typedef struct WifiMsg {
    int command;
    int x;
    int y;
    int action; /* 0表示没有触发活动，1表示触发告警，2表示触发清扫 */
} WifiMsg;

void send_msg(const WifiMsg *msg);

#endif //E4C061EA8E754A4993CFDE1363CD7138
