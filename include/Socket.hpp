#pragma once

#include <winsock2.h>

class Socket {
public:
	Socket();
	~Socket();

	Socket(const Socket&) = delete;
	Socket& operator=(const Socket&) = delete;

	bool Create();
	bool Bind(int port);
	bool Listen();

private:
	SOCKET m_socket;
};