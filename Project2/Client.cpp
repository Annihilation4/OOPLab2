#include "Client.h"

// Ініціалізація статичного поля
int Client::clientCount = 0;

std::vector<Client> Client::staticClients;
std::vector<Client*> Client::dynamicClients;