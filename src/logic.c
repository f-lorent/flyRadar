//
// Created by florent on 18/07/25.
//

#include <stdlib.h>
#include <curl/curl.h>
#include "../include/parse.h"

#include "../include/requestAPI.h"

typedef enum {
    INIT = 0,
    FETCH,
    PARSE,
    ANALYZE,
    DONE,
    FINISH,
    ERROR
}state_e;

void stateMachine(const char *cURL) {
    static struct memory output;
    static state_e state = INIT;
    static const char *url;

    while (state != DONE) {
        switch (state) {
            case INIT:
                curl_global_init(CURL_GLOBAL_DEFAULT);
                output.response = NULL;
                output.size = 0;
                url = cURL;
                printf("========flyRADAR========\n");
                if (tryHeaders(url)) {
                    state = FETCH;
                }else {
                    state = ERROR;
                }
                break;

            case FETCH:
                curlData(url, &output);
                state = PARSE;
                break;

            case PARSE:
                parse(output.response);
                state = ANALYZE;
                break;

            case ANALYZE:
                state = FINISH;
                break;

            case ERROR:
                printf("Erreur: l'url n'existe pas\n");
                state = FINISH;
                break;

            case FINISH:
                if (output.response) {
                    free(output.response);
                    output.response = NULL;
                }
                curl_global_cleanup();
                printf("========flyRADAR========\n");
                state = DONE;
                break;
        }
    }
}