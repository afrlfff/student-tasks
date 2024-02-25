#include "..\h\lib.h"
#include "..\h\FundList.h"
#include "..\h\ClientsList.h"
#include "..\h\func.h"
#include "..\h\FundList.h"
#include "..\h\GetClients.h"
#include "..\h\GetMoney.h"
#include "..\h\Process.h"
#include "..\h\Operator==.h"

int main()
{
	setlocale(LC_ALL, "ru");

	FundList Fund;
	ClientsList Clients;
	fstream fprotok; fprotok.open("protokol.txt", ios::out | std::ios::binary);
	fprotok << "ПРОТОКОЛ К КУРСОВОЙ РАБОТЕ.\n\n";

	if (GetMoney(&Fund, &fprotok) && GetClients(&Clients, &fprotok))
	{
		fprotok	<< "Считанный фонд организации(R = " << Fund.R << " ден. ед.):\n";
		Fund.out_list(&fprotok);
		fprotok << "\nСчитанные клиенты(" << Clients.N << " кл.):\n";
		Clients.out_list(&fprotok);
		
		Process(&Fund, &Clients, &fprotok);
	}

	Fund.delete_list();
	Clients.delete_list();
	fprotok.close(); return 0;
}

