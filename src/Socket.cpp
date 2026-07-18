#include "Socket.hpp"
#include <iostream>

Socket::Socket() : m_socket(INVALID_SOCKET) {
	WSADATA wsaData;

	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0) {
		std::cerr << "WSAStartup failed: " << result << std::endl;
	}
}

Socket::~Socket() {
	if (m_socket != INVALID_SOCKET) {
		closesocket(m_socket);
	}
	WSACleanup();
}

bool Socket::Create() {
	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_socket == INVALID_SOCKET) {
		std::cerr << "Socket creation failed with error: " << WSAGetLastError() << std::endl;
		return false;
	}
	return true;
}

bool Socket::Bind(int port) {
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = INADDR_ANY;
	service.sin_port = htons(port);

	int result = bind(m_socket, reinterpret_cast<SOCKADDR*>(&service), sizeof(service));

	if (result == SOCKET_ERROR) {
		std::cerr << "Bind failed with error: " << WSAGetLastError() << std::endl;
		return false;
	}
	return true;
}