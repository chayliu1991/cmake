#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE *fp = NULL;

int write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    int len = fwrite(ptr, size, nmemb, (FILE *)fp);
    return len;
}

int main(void)
{
    const char *file_name = "baidu";
    const char *mode = "wb";

    fp = fopen(file_name, mode);
    if (fp == NULL)
    {
        perror("fopen()");
        exit(-1);
    }

    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

    CURLcode res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);

    return 0;
}