#define NOMINMAX
#define byte win_byte_temp_fix
#include <windows.h>
#undef byte
#include "ApiClient.h"
#include <curl/curl.h>
#include <iostream>

const std::string BASE_URL = "http://localhost:8000/api";

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* out) {
    size_t totalSize = size * nmemb;
    out->append((char*)contents, totalSize);
    return totalSize;
}

string ApiClient::Post(const string& endpoint, const string& jsonData,const string & token) {
    CURL* curl = curl_easy_init();
    string response;

    if (curl) {
        string url = BASE_URL + endpoint;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonData.c_str());

        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    return response;
}
string ApiClient::extract(const string& jsonText, const string& key) {
    // Format to look for: "key":"value"
    string pattern = "\"" + key + "\":\"";
    size_t start = jsonText.find(pattern);
    if (start == string::npos) {
        return "";
    }

    start += pattern.length(); // Move past the key and quotes
    size_t end = jsonText.find("\"", start);
    if (end == string::npos) {
        return "";
    }

    return jsonText.substr(start, end - start);
}
string ApiClient::Get(const string& endpoint, const string& token) {
    CURL* curl = curl_easy_init();
    string response;

    if (curl) {
        string url = BASE_URL + endpoint;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        if (!token.empty()) {
            string authHeader = "Authorization: Bearer " + token;
            headers = curl_slist_append(headers, authHeader.c_str());
        }

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            cerr << "GET failed: " << curl_easy_strerror(res) << endl;
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    return response;
}