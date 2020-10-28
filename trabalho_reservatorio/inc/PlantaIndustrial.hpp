#ifndef PLANTAINDUSTRIAL_H
#define PLANTAINDUSTRIAL_H

#include "bomba.h"
#include "reservatorio.h"

class PlantaIndustrial
{
private:
public:
    PlantaIndustrial(Bomba &b1, Bomba &b2, Reservatorio &r1);
};

PlantaIndustrial::PlantaIndustrial(Bomba &b1, Bomba &b2, Reservatorio &r1)
{
    b1.corrente.lerDados();
    b1.tensao.lerDados();
    b2.corrente.lerDados();
    b2.tensao.lerDados();
    r1.v1.lerDados();
    r1.v2.lerDados();
    int x, op, hora, min, seg, indice, indice2;
    int indice1 = 0, k = 1;
    double volume1, volume2, vTotal;
    string h;

    while (k == 1)
    {
        system("cls");
        std::cout << "Bem vindo(a)!" << endl;
        std::cout << "Selecione a operacao desejada : \n 1-Vazao de entrada e/ou de saida do tanque.\n 2-Volume do reservatorio \n 3-Nome de um sensor \n 4-ID de um sensor \n 5-Valor RMS de um sensor (corrente ou tensao) \n 6-Potencia de determinada bomba \n 7-Potencia aparente de determinada bomba \n 8-Fator de potencia de uma determinada bomba \n 9-Energia consumida por uma determinada bomba \n 10-Sair " << endl;
        cin >> x;

        switch (x)
        {
        case 1:

            system("cls");
            cout << " Escolha uma opcao : \n 1-Vazao de entrada\n 2-Vazao de saida " << endl;
            cin >> op;
            if (op == 1)
            {
                cout << "Digite o horario desejado no formato hh:mm:ss:: ";
                cin >> h;
                hora = (int)stod(h.substr(0, 2));
                min = (int)stod(h.substr(3, 2));
                seg = (int)stod(h.substr(6, 2));

                indice = hora * 3600 + min * 60 + seg;
                indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice2 = indice;
                system("cls");
                cout << "Vazao de entrada neste horario : " << r1.v1.getDado(indice2) << r1.v1.getUnidade() << endl;
                cout << "1-Voltar para o menu      2-Sair" << endl;
                cin >> op;
                system("cls");
                if (op == 2)
                {
                    k = 0;
                }
            }
            else if (op == 2)
            {
                system("cls");
                cout << "Digite o horario desejado no formato hh:mm:ss:: ";
                cin >> h;
                hora = (int)stod(h.substr(0, 2));
                min = (int)stod(h.substr(3, 2));
                seg = (int)stod(h.substr(6, 2));

                indice = hora * 3600 + min * 60 + seg;
                indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice2 = indice;
                system("cls");
                cout << "Vazao de saida neste horario : " << r1.v2.getDado(indice2) << r1.v2.getUnidade() << endl;

                cout << "1-Voltar para o menu      2-Sair" << endl;
                cin >> op;
                if (op == 2)
                {
                    k = 0;
                }
            }

        break;

        case 2:
            system("cls");
            cout << "Digite o horario no formato hh:mm:ss : ";
            cin >> h;
            hora = (int)stod(h.substr(0, 2));
            min = (int)stod(h.substr(3, 2));
            seg = (int)stod(h.substr(6, 2));

            indice = hora * 3600 + min * 60 + seg;
            indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
            indice2 = indice;
            system("cls");
            cout << "Volume no reservatorio neste horario: " << r1.getVolume(indice2) << " litros." << endl;
            cout << "1-Voltar para o menu      2-Sair" << endl;
            cin >> op;
            if (op == 2)
            {
                k = 0;
            }
            break;

        case 3:
            system("cls");
            cout << "Escolha a opcao correspondente ao sensor desejado :  " << endl;
            cout << "1-Reservatorio \n 2-Eletrico " << endl;
            cin >> op;
            if (op == 1)
            {
                system("cls");
                cout << "Escolha uma opcao : \n 1-Vazao de entrada \n 2-Vazao de saida " << endl;
                cin >> op;
                if (op == 1)
                {   
                    system("cls");
                    cout << "Nome do sensor escolhido: " << r1.v1.getNome() << endl;
                    cout << "1- Voltar para o menu     2- Sair" << endl;
                    cin >> op;
                    if (op == 2)
                    {
                        k = 0;
                    }
                }
                else if (op == 2)
                {
                    system("cls");
                    cout << "Nome do sensor escolhido: " << r1.v2.getNome() << endl;
                    cout << "1-Voltar para o menu     2-Sair" << endl;
                    cin >> op;
                    if (op == 2)
                    {
                        k = 0;
                    }
                }
            }
            else if (op == 2)
            {
                system("cls");
                cout << "Escolha a bomba : \n 1-Bomba 1    2-Bomba 2" << endl;
                cin >> op;
                if (op == 1)
                {
                    system("cls");
                    cout << "Escolha o sensor : \n 1-Sensor de Corrente \n 2- Sensor de tensao" << endl;
                    cin >> op;
                    if (op == 1)
                    {   
                        system("cls");
                        cout << "Nome do sensor escolhido : " << b1.corrente.getNome() << endl;
                        cout << " 1-Voltar para o menu   2-Sair";
                        cin >> op;
                        if (op == 2)
                        {
                            k = 0;
                        }
                    }
                    else if (op == 2)
                    {
                        system("cls");
                        cout << "Nome do sensor escolhido : " << b1.tensao.getNome() << endl;
                        cout << " 1-Voltar para o menu   2-Sair";
                        cin >> op;
                        if (op == 2)
                        {
                            k = 0;
                        }
                    }
                }
                else if (op == 2)
                {
                    system("cls");
                    cout << "Escolha o sensor : \n 1- Sensor de Corrente \n 2- Sensor de tensao" << endl;
                    cin >> op;
                    if (op == 1)
                    {
                        system("cls");
                        cout << "Nome do sensor escolhido : " << b2.corrente.getNome() << endl;
                        cout << " 1-Voltar para o menu   2-Sair";
                        cin >> op;
                        if (op == 2)
                        {
                            k = 0;
                        }
                    }
                    else if (op == 2)
                    {
                        system("cls");
                        cout << "Nome do sensor escolhido : " << b2.tensao.getNome() << endl;
                        cout << " 1-Voltar para o menu   2-Sair";
                        cin >> op;
                        if (op == 2)
                        {
                            k = 0;
                        }
                    }
                }
            }
            break;

        case 4:
            system("cls");
            cout << "Escolha a opcao correspondente ao sensor desejado :  " << endl;
            cout << " 1-Reservatorio \n 2-Bomba " << endl;
            cin >> op;
            if (op == 1)
            {
                system("cls");
                cout << "Escolha uma opcao : \n 1- Vazao de entrada \n 2- Vazao de saida " << endl;
                cin >> op;
                if (op == 1)
                {
                    system("cls");
                    cout << "ID do sensor escolhido: " << r1.v1.getId() << endl;
                    cout << "1- Voltar para o menu     2- Sair" << endl;
                    cin >> op;
                    if (op == 2)
                    {
                        k = 0;
                    }
                }
                else if (op == 2)
                {
                    system("cls");
                    cout << "ID do sensor escolhido: " << r1.v2.getId() << endl;
                    cout << "1-Voltar para o menu     2-Sair" << endl;
                    cin >> op;
                    if (op == 2)
                    {
                        k = 0;
                    }
                }
            }
            else if (op == 2)
            {
                system("cls");
                cout << "Escolha a bomba : \n Bomba 1    Bomba 2" << endl;
                cin >> op;
                if (op == 1)
                {
                    system("cls");
                    cout << "Escolha o sensor : \n 1- Sensor de Corrente \n 2- Sensor de tensao" << endl;
                    cin >> op;
                    if (op == 1)
                    {
                        system("cls");
                        cout << "ID do sensor escolhido : " << b1.corrente.getId() << endl;
                        cout << " 1-Voltar para o menu   2-Sair";
                        cin >> op;
                        if (op == 2)
                        {
                            k = 0;
                        }
                    }
                    else if (op == 2)
                    {
                        system("cls");
                        cout << "ID do sensor escolhido : " << b1.tensao.getId() << endl;
                        cout << " 1-Voltar para o menu   2-Sair";
                        cin >> op;
                        if (op == 2)
                        {
                            k = 0;
                        }
                    }
                }
                else if (op == 2)
                {   
                    system("cls");
                    cout << "Escolha o sensor : \n 1- Sensor de Corrente \n 2- Sensor de tensao" << endl;
                    cin >> op;
                    if (op == 1)
                    {   
                        system("cls");
                        cout << "ID do sensor escolhido : " << b2.corrente.getId() << endl;
                        cout << " 1-Voltar para o menu   2-Sair";
                        cin >> op;
                        if (op == 2)
                        {
                            k = 0;
                        }
                    }
                    else if (op == 2)
                    {
                        system("cls");
                        cout << "ID do sensor escolhido : " << b2.tensao.getId() << endl;
                        cout << " 1-Voltar para o menu   2-Sair";
                        cin >> op;
                        if (op == 2)
                        {
                            k = 0;
                        }
                    }
                }
            }
            break;

        case 5:
            system("cls");
            cout << "Escolha a bomba : \n 1- Bomba 1      2- Bomba 2" << endl;
            cin >> op;
            cout << "Digite o horario desejado no formato hh:mm:ss:: ";
            cin >> h;
            hora = (int)stod(h.substr(0, 2));
            min = (int)stod(h.substr(3, 2));
            seg = (int)stod(h.substr(6, 2));

            indice = hora * 3600 + min * 60 + seg;
            indice = indice - 65335; 
            indice2 = indice;
            if (op == 1)
            {
                system("cls");
                cout << "1-Corrente    2-Tensao" << endl;
                cin >> op;

                if (op == 1)
                {
                    system("cls");
                    cout << "Valor RMS : " << b1.corrente.getRMS(indice2) << " A"
                         << "\n 1-Voltar ao menu     2-Sair" << endl;
                    cin >> op;
                    if (op == 2)
                    {
                        k = 0;
                    }
                }
                else if (op == 2)
                {
                    system("cls");
                    cout << "Valor RMS : " << b1.tensao.getRMS(indice2) << " V"
                         << "\n 1-Voltar ao menu     2-Sair" << endl;
                    cin >> op;
                    if (op == 2)
                    {
                        k = 0;
                    }
                }
            }
            else if (op == 2)
            {
                system("cls");
                cout << "1-Corrente    2-Tensao" << endl;
                cin >> op;

                if (op == 1)
                {
                    system("cls");
                    cout << "Valor RMS : " << b2.corrente.getRMS(indice2) << " A"
                         << "\n 1-Voltar ao menu     2-Sair" << endl;
                    cin >> op;
                    if (op == 2)
                    {
                        k = 0;
                    }
                }
                else if (op == 2)
                {
                    system("cls");
                    cout << "Valor RMS : " << b2.tensao.getRMS(indice2) << " V "
                         << "\n 1-Voltar ao menu     2-Sair" << endl;
                    cin >> op;
                    if (op == 2)
                    {
                        k = 0;
                    }
                }
            }
            break;
        case 6:
            system("cls");
            cout << "Escolha a bomba: \n 1-Bomba 1 \n 2- Bomba2" << endl;
            cin >> op;
            if (op == 1)
            {
                system("cls");
                cout << "Digite o horario no formato hh:mm:ss : " << endl;
                cin >> h;
                hora = (int)stod(h.substr(0, 2));
                min = (int)stod(h.substr(3, 2));
                seg = (int)stod(h.substr(6, 2));

                indice = hora * 3600 + min * 60 + seg;
                indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice2 = indice;
                system("cls");
                cout << "Potencia ativa neste horario : " << b1.calcPot(indice2) << " W "
                     << "\n 1-Voltar ao menu     2-Sair" << endl;
                cin >> op;
                if (op == 2)
                {
                    k = 0;
                }
            }
            else if (op == 2)
            {
                system("cls");
                cout << "Digite o horario no formato hh:mm:ss : " << endl;
                cin >> h;
                hora = (int)stod(h.substr(0, 2));
                min = (int)stod(h.substr(3, 2));
                seg = (int)stod(h.substr(6, 2));

                indice = hora * 3600 + min * 60 + seg;
                indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice2 = indice;
                system("cls");
                cout << "Potencia ativa neste horario : " << b2.calcPot(indice2) << " W "
                     << "\n 1-Voltar ao menu     2-Sair" << endl;
                cin >> op;
                if (op == 2)
                {
                    k = 0;
                }
            }

            break;
        case 7:
            system("cls");
            cout << "Escolha a bomba: \n 1-Bomba 1 \n 2- Bomba2" << endl;
            cin >> op;
            if (op == 1)
            {
                system("cls");
                cout << "Digite o horario no formato hh:mm:ss : " << endl;
                cin >> h;
                hora = (int)stod(h.substr(0, 2));
                min = (int)stod(h.substr(3, 2));
                seg = (int)stod(h.substr(6, 2));

                indice = hora * 3600 + min * 60 + seg;
                indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice2 = indice;
                system("cls");
                cout << "Potencia aparente neste horario : " << b1.calcPotAparente(indice2) << " VA "
                     << "\n 1-Voltar ao menu     2-Sair" << endl;
                cin >> op;
                if (op == 2)
                {
                    k = 0;
                }
            }
            else if (op == 2)
            {
                system("cls");
                cout << "Digite o horario no formato hh:mm:ss : " << endl;
                cin >> h;
                hora = (int)stod(h.substr(0, 2));
                min = (int)stod(h.substr(3, 2));
                seg = (int)stod(h.substr(6, 2));

                indice = hora * 3600 + min * 60 + seg;
                indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice2 = indice;
                system("cls");
                cout << "Potencia aparente neste horario : " << b2.calcPotAparente(indice2) << " VA "
                     << "\n 1-Voltar ao menu     2-Sair" << endl;
                cin >> op;
                if (op == 2)
                {
                    k = 0;
                }
            }
            break;
        case 8:
            system("cls");
            cout << "Escolha a bomba: \n 1-Bomba 1 \n 2- Bomba2" << endl;
            cin >> op;
            if (op == 1)
            {
                system("cls");
                cout << "Digite o horario no formato hh:mm:ss : " << endl;
                cin >> h;
                hora = (int)stod(h.substr(0, 2));
                min = (int)stod(h.substr(3, 2));
                seg = (int)stod(h.substr(6, 2));

                indice = hora * 3600 + min * 60 + seg;
                indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice2 = indice;
                system("cls");
                cout << "Fator de potencia neste horario : " << b1.CalculaFP(indice2)
                     << "\n 1-Voltar ao menu     2-Sair" << endl;
                cin >> op;
                if (op == 2)
                {
                    k = 0;
                }
            }
            else if (op == 2)
            {
                system("cls");
                cout << "Digite o horario no formato hh:mm:ss : " << endl;
                cin >> h;
                hora = (int)stod(h.substr(0, 2));
                min = (int)stod(h.substr(3, 2));
                seg = (int)stod(h.substr(6, 2));

                indice = hora * 3600 + min * 60 + seg;
                indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice2 = indice;
                system("cls");
                cout << "Fator de potencia neste horario : " << b2.CalculaFP(indice2) << "\n 1- Voltar ao menu     2- Sair" << endl;
                cin >> op;
                if (op == 2)
                {
                    k = 0;
                }
            }
            break;
        case 9:
            system("cls");
            cout << "Escolha a bomba: \n 1-Bomba 1 \n 2- Bomba2" << endl;
            cin >> op;
            if (op == 1)
            {
                system("cls");
                cout << "Digite o horario de inicio do intervalo no formato hh:mm:ss : " << endl;
                cin >> h;
                hora = (int)stod(h.substr(0, 2));
                min = (int)stod(h.substr(3, 2));
                seg = (int)stod(h.substr(6, 2));

                indice = hora * 3600 + min * 60 + seg;
                indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice1 = indice;

                cout << "Digite o horario de termino do intervalo no formato hh:mm:ss : " << endl;
                cin >> h;
                hora = (int)stod(h.substr(0, 2));
                min = (int)stod(h.substr(3, 2));
                seg = (int)stod(h.substr(6, 2));

                indice = hora * 3600 + min * 60 + seg;
                indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice2 = indice;
                system("cls");
                cout << "Energia neste intervalo de tempo : " << b1.calcEnergia(indice1, indice2) << " kWh "
                     << "\n 1-Voltar ao menu     2-Sair" << endl;
                cin >> op;
                if (op == 2)
                {
                    k = 0;
                }
            }
            else if (op == 2)
            {
                system("cls");
                cout << "Digite o horario de inicio do intervalo no formato hh:mm:ss : " << endl;
                cin >> h;
                hora = (int)stod(h.substr(0, 2));
                min = (int)stod(h.substr(3, 2));
                seg = (int)stod(h.substr(6, 2));

                indice = hora * 3600 + min * 60 + seg;
                indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice1 = indice;

                cout << "Digite o horario de término do intervalo no formato hh:mm:ss : " << endl;
                cin >> h;
                hora = (int)stod(h.substr(0, 2));
                min = (int)stod(h.substr(3, 2));
                seg = (int)stod(h.substr(6, 2));

                indice = hora * 3600 + min * 60 + seg;
                indice = indice - 65335; //65335 é a hora inicial em segundos, quando subtrai isso da hora desejada obtem o indice
                indice2 = indice;
                system("cls");
                cout << "Energia neste intervalo de tempo : " << b2.calcEnergia(indice1, indice2) << " kWh "
                     << "\n 1-Voltar ao menu     2-Sair" << endl;
                cin >> op;
                if (op == 2)
                {
                    k = 0;
                }
            }
            break;
        default:
            k = 0;
            break;
        }
    }
}
#endif