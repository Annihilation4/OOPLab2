#include "Client.h"

// ����������� ���������� ����
int Client::clientCount = 0;

std::vector<Client> Client::staticClients;
std::vector<Client*> Client::dynamicClients;