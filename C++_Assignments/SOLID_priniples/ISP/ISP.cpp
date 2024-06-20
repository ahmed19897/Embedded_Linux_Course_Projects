// no client should be forced to depend on methods it doesn't use


#include <vector>
#include <memory>
struct Document;

//  struct IMachine
// {
// 	virtual void print(std::vector<Document*> docs) = 0;
// 	virtual void scan(std::vector<Document*> docs) = 0;
// 	virtual void fax(std::vector<Document*> docs) = 0;
// }; 
// //

// struct MFP : IMachine
// {
// 	void print(std::vector<Document*> docs) override;
// 	void scan(std::vector<Document*> docs) override;
// 	void fax(std::vector<Document*> docs) override;
// };

struct IPrinter
{
	virtual void print(std::vector<Document*> docs) = 0;
};

struct IScanner
{
	virtual void scan(std::vector<Document*> docs) = 0;
};

struct IFax
{
	virtual void fax(std::vector<Document*> docs) = 0;
};

struct IMachine : IPrinter,IScanner
{
	IPrinter& printer;
	IScanner& scanner;

	IMachine(IPrinter& printer, IScanner& scanner)
		: printer(printer),
		  scanner(scanner)
	{
	}

	void print(std::vector<Document*> docs) override
	{
		printer.print(docs);
	}
	void scan(std::vector<Document*> docs) override
	{
		scanner.scan(docs);
	}
};


int main()
{
    // std::unique_ptr<IPrinter> p=std::make_unique<IPrinter>();
    // std::unique_ptr<IScanner> S=std::make_unique<IScanner>();

    // IMachine TwoInOnePrinter(*p,*S);

    return 0;
}