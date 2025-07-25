//
// Created by florent on 18/07/25.
//

#ifndef REQUESTAPI_H
#define REQUESTAPI_H

struct memory {
    char *response;
    size_t size;
};

int tryHeaders(const char *url);

void curlData(const char *url, struct memory *output);

#endif //REQUESTAPI_H
