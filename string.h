
#include <iostream>
using namespace std;
#include <random>
#include "other.h"
#include <urlmon.h>
#include <iostream>
#pragma comment(lib, "urlmon.lib")
#include <stdio.h>
#include <windows.h>
#include <Windows.h>
#include <tchar.h>
#include <Wininet.h>
#include <filesystem>


HINTERNET user_agent = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL); // CLIENT USER AGENT
HINTERNET content_url; // WILL BE USED FOR TELL TO THE PROGRAM TO GO ON THE LINK YOU SET.
string ret_network;
codex_string replaceAll(string base, const string& search,
	const string& replace) {
	size_t pos = 0;
	while ((pos = base.find(search, pos)) != string::npos) {
		base.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return base;
}
codex_string read_data(string URL) {
	if (user_agent) {
		content_url = InternetOpenUrlA(user_agent, URL.c_str(), NULL, NULL, NULL, NULL);
		if (content_url) {
			char buffer[2000];
			DWORD bytesRead;
			do {
				InternetReadFile(content_url, buffer, 2000, &bytesRead);
				ret_network.append(buffer, bytesRead);
				memset(buffer, 0, 2000);
			} while (bytesRead);
			InternetCloseHandle(user_agent);
			InternetCloseHandle(content_url);
			string p = replaceAll(ret_network, "|n", "\r\n");
			return p;
		}
	}
	InternetCloseHandle(user_agent);
	string p = replaceAll(ret_network, "|n", "\r\n");
	return p;
}