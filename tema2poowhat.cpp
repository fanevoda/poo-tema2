#include <iostream>
#include <vector>

using namespace std;

class Contract
{
private:
    int nrContract;
    int an;
    string beneficiar;
    string furnizor;
    int valoare;

public:

    Contract()
    {
        nrContract = -1;
        an = -1;
        beneficiar = "???";
        furnizor = "???";
        valoare = -1;
    }
    Contract(const int _nrContract, const int _an, const string _beneficiar, const string _furnizor, const int _valoare)
    {
        nrContract = _nrContract;
        an = _an;
        beneficiar = _beneficiar;
        furnizor = _furnizor;
        valoare = _valoare;
    }

    Contract(const Contract& other)
    {
        nrContract = other.nrContract;
        an = other.an;
        beneficiar = other.beneficiar;
        furnizor = other.furnizor;
        valoare = other.valoare;
    }
    ~Contract() {}

    const int get_nrContract()
    {
        return nrContract;
    }
    const int get_an()
    {
        return an;
    }
    const string get_beneficiar()
    {
       return beneficiar;
    }
    const string get_furnizor()
    {
        return furnizor;
    }
    const int get_valoare()
    {
        return valoare;
    }

    int* getp_nrContract()
    {
        return &nrContract;
    }
    int* getp_an()
    {
        return &an;
    }
    string* getp_beneficiar()
    {
        return &beneficiar;
    }
    string* getp_furnizor()
    {
        return &furnizor;
    }
    int* getp_valoare()
    {
        return &valoare;
    }

    void set_nrContract(const int x)
    {
        nrContract = x;
    }
    void set_an(const int x)
    {
        an = x;
    }
    void set_beneficiar(const string x)
    {
        beneficiar = x;
    }
    void set_furnizor(const string x)
    {
        furnizor = x;
    }
    void set_valoare(const int x)
    {
        valoare = x;
    }

    void Update(const int _nrContract, const int _an, const string _beneficiar, const string _furnizor, const int _valoare)
    {
        nrContract = _nrContract;
        an = _an;
        beneficiar = _beneficiar;
        furnizor = _furnizor;
        valoare = _valoare;
    }

    Contract* getAddress()
    {
        return this;
    }


    void Update(const Contract& other)
    {
        nrContract = other.nrContract;
        an = other.an;
        beneficiar = other.beneficiar;
        furnizor = other.furnizor;
        valoare = other.valoare;
    }

    void Afisare()
    {
        cout << "Contractul cu numarul " << nrContract << " din anul " << an << " cu beneficiarul " << beneficiar << " si cu furnizorul " << furnizor << " in valoare de " << valoare << endl;
    }

    virtual void cecontractsunt()
    {
        cout << "sunt contract simplu";
    }
 
// functie virtuala pusa aici doar de dragul de a fi o functie virtuala in cod, nu stiu as folosi una la problema aceasta

    Contract& operator=(Contract& other)
    {
        other.nrContract = nrContract;
        other.an = an;
        other.beneficiar = beneficiar;
        other.furnizor = furnizor;
        other.valoare = valoare;
        return *this;
    }


    friend ostream& operator<<(ostream& os, Contract& angajat);
    friend istream& operator>>(istream& is, Contract& angajat);

};
      
ostream& operator<<(ostream& os, Contract& contract)
{
    os << "Contractul cu numarul "<< contract.nrContract << " din anul " << contract.an << " cu beneficiarul " << contract.beneficiar << " si cu furnizorul " << contract.furnizor << " in valoare de " << contract.valoare << endl;
    return os;
}

istream& operator>>(istream& is, Contract& contract)
{
    cout << "Numarul contractului este: ";
     
    bool validInput = false;

    while (!validInput)
    {
        try
        {
            if (is >> contract.nrContract)
                validInput = true;
            else
                throw "na vrut";
        }
        catch (...)
        {
            cout << "Input invalid. Mai incearca o data. ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }

    cout << "Anul semnarii contractului de cumparare este: ";

    validInput = false;

    while (!validInput)
    {
        try
        {
            if (is >> contract.an)
                validInput = true;
            else
                throw "na vrut";
        }
        catch (...)
        {
            cout << "Input invalid. Mai incearca o data. ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }

    cout << "Numele benificiarului este: ";
    is >> contract.beneficiar;
    cout << "Numele furnizorului este: ";
    is >> contract.furnizor;
    
    
    cout << "Valoarea contractului este de: ";

    validInput = false;

    while (!validInput)
    {
        try
        {
            if (is >> contract.valoare)
                validInput = true;
            else
                throw "na vrut";
        }
        catch (...)
        {
            cout << "Input invalid. Mai incearca o data. ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }
    
    return is;
}


class ContractInchiriere : Contract
{
private:
    int perioada;
    Contract* _bazaContract = getAddress();

public:

    ContractInchiriere() : Contract()
    {
        perioada = -1;
    }
    ContractInchiriere(int _perioada)
    {
        perioada = _perioada;
    }
    ContractInchiriere(int _perioada, int _nrContract, int _an, string _beneficiar, string _furnizor, int _valoare)
    {
        perioada = _perioada;
        Update(_an, _nrContract, _beneficiar, _furnizor, _valoare);
    }

    ContractInchiriere(ContractInchiriere& other)
    {
        perioada = other.perioada;
        *getp_an() = other.get_an();
        *getp_nrContract() = other.get_nrContract();
        *getp_beneficiar() = other.get_beneficiar();
        *getp_furnizor() = other.get_furnizor();
        *getp_valoare() = other.get_valoare();
    }

    ~ContractInchiriere() {}  

    Contract* get_bazaContract()
    {
        return _bazaContract;
    }

    const int get_perioada()
    {
        return perioada;
    }

    void cecontractsunt()
    {
        cout << "sunt contract inchiriere";
    }

    ContractInchiriere& operator=(ContractInchiriere& other)
    {
        perioada = other.perioada;
        Update(other);
        return *this;
    }

    friend ostream& operator<<(ostream& os, ContractInchiriere& ContractInchiriere);
    friend istream& operator>>(istream& is, ContractInchiriere& ContractInchiriere);
};

ostream& operator<<(ostream& os, ContractInchiriere& ContractInchiriere)
{
    os << "Contractul cu numarul " << ContractInchiriere._bazaContract->get_nrContract() << " din anul " << ContractInchiriere._bazaContract->get_an() << " cu beneficiarul " << ContractInchiriere._bazaContract->get_beneficiar() << " si cu furnizorul " << ContractInchiriere._bazaContract->get_furnizor() << " in valoare de " << ContractInchiriere._bazaContract->get_valoare() << " RON ";
    os << " pe o perioada de " << ContractInchiriere.perioada << " luni." << endl;
    return os;
}

istream& operator>>(istream& is, ContractInchiriere& ContractInchiriere)
{   
    is >> *ContractInchiriere._bazaContract;
    
    bool validInput = false;

    while (!validInput)
    {
        try
        {
            if (is >> ContractInchiriere.perioada)
                validInput = true;
            else
                throw "na vrut";
        }
        catch (...)
        {
            cout << "Input invalid. Mai incearca o data. ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }

    return is;
}


class Dosar
{
private:
    int nrContracte;
    vector<ContractInchiriere*> Contracte;
public:

    Dosar()
    {
        nrContracte = 0;
    }

    Dosar(ContractInchiriere* v[], const int nrElem)
    {
        nrContracte = nrElem;

        for (int i = 0; i < nrContracte; i++)
            Contracte.push_back(v[i]);
    }

    Dosar(Dosar& other)
    {
        nrContracte = other.nrContracte;

        for (int i = 0; i < nrContracte; i++)
            Contracte.push_back(other.Contracte[i]);
    }
    ~Dosar() {}

    const int get_nrContracte()
    {
        return nrContracte;
    }

    const int get_valContract(int i)
    {
        return Contracte[i]->get_bazaContract()->get_valoare();
    }

    const int get_perioada(int i)
    {
        return Contracte[i]->get_perioada();
    }

    Dosar& operator=(Dosar& other)
    {
        nrContracte = other.nrContracte;
        for (int i = 0; i < nrContracte; i++)
            Contracte.push_back(other.Contracte[i]);
        return *this;
    }

    friend ostream& operator<<(ostream& os, Dosar& Dosar);
    friend istream& operator>>(istream& os, Dosar& Dosar);
};


ostream& operator<<(ostream& os, Dosar& Dosar)
{
    os << "Dosarul are " << Dosar.nrContracte << " contacte." << endl;
    for (int i = 0; i < Dosar.nrContracte; i++)
    {
        os << *Dosar.Contracte[i] << endl;
    }
    return os;
}

istream& operator>>(istream& is, Dosar& Dosar)
{
    cout << "Cate contracte dorim sa introducem? ";

    bool validInput = false;

    while (!validInput)
    {
        try
        {
            if (is >> Dosar.nrContracte)
                validInput = true;
            else
                throw "na vrut";
        }
        catch (...)
        {
            cout << "Input invalid. Mai incearca o data. ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }
    
    for (int i = 0; i < Dosar.nrContracte; i++)
    {
        cout << "Contractul " << i+1 << ":\n";
        Dosar.Contracte.push_back(new ContractInchiriere);
        is >> *Dosar.Contracte[i];
    }
    return is;
}


int main()
{
    // Contract pana(1, 2003, "fane", "fanoiu de vara", 100);

    /* nici upcast sau downcast nu stiu cum as folosi dar cred ca ar arata asa

    Contract _contract;
    ContractInchiriere _contractInchiriere;

    Contract* _p_contractInchiriere = &_contractInchiriere;
    ContractInchiriere* _p_contract = &_contract;

    */

    Dosar _dosar;

    cin >> _dosar;

    cout << _dosar;

    const int n = _dosar.get_nrContracte();
    int s = 0;

    for (int i = 0; i < n; i++)
    {
        s += _dosar.get_valContract(i);
        cout << "Contractul " << i+1 << " a incasat " << (double)(_dosar.get_valContract(i) / _dosar.get_perioada(i)) << " RON lunar." << endl;
    }

    cout << "In total au fost incasati " << s << " RON.";

  
}

