typedef struct contabancaria ContaBancaria;

ContaBancaria * cria_conta(char titular[81], int numero, float saldo);

void deposita(ContaBancaria*c, float valor);

void saca(ContaBancaria*c, float valor);

void transfere(ContaBancaria*c1, ContaBancaria*c2, float valor);

float saldo(ContaBancaria*c);

void exclui_conta(ContaBancaria*c);