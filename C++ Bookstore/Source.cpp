#include "Book.h"
#include "Customer.h"
#include "Person.h"
#include "Author.h"
#include "Util.h"
#include "NameExc.h"
#include "PhoneNumberExc.h"
#include <memory>
#include <fstream>

std::vector<std::unique_ptr<Book>> Book::bookList;

int main() {

    std::string customerFirstName, customerLastName, customerPhoneNumber, bookID, continueShopping, purchaseConfirmation, transactionConfirmation, transactionReview;
    int customerAge, transactionNumber = 1;
    std::ofstream outfile;
    std::ifstream infile;

    std::unique_ptr<Person> author1 = std::make_unique<Author>("Milan", "Milanovic", "Belgrade");
    std::unique_ptr<Person> author2 = std::make_unique<Author>("Conn", "Iggulden", "London");
    std::unique_ptr<Person> author3 = std::make_unique<Author>("Maja", "Vilotijevic", "Kragujevac");

    std::cout << "Most popular authors: " << std::endl;
    author1->info();
    author2->info();
    author3->info();

    std::cout << std::endl;

    std::unique_ptr<Book> book1 = std::make_unique<Book>("01", "The Fire Gate", (Author&)(*author1), 3000, 10); // C-style dynamic casting
    std::unique_ptr<Book> book2 = std::make_unique<Book>("02", "The Gates of Athens", dynamic_cast<Author&>(*author2), 2600, 17); // C++-style dynamic casting
    std::unique_ptr<Book> book3 = std::make_unique<Book>("03", "Aperkat", dynamic_cast<Author&>(*author3), 860.30, 9);

    Book::addBook(std::move(book1));
    Book::addBook(std::move(book2));
    Book::addBook(std::move(book3));

    Book::printBookList();

    std::unique_ptr<Customer> customer = std::make_unique<Customer>();

    try
    {
        std::cout << "Enter your first name: ";
        std::cin >> customerFirstName;
        customer->setFirstName(customerFirstName);
        std::cout << std::endl;

        if (Util::onlyLetters(customerFirstName) == 0)
        {
            throw NameExc();
        }

        std::cout << "Enter your last name: ";
        std::cin >> customerLastName;
        customer->setLastName(customerLastName);
        std::cout << std::endl;

        if (Util::onlyLetters(customerLastName) == 0)
        {
            throw NameExc();
        }

    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Enter your age: ";
    std::cin >> customerAge;
    customer->setAge(customerAge);
    std::cout << std::endl;

    try
    {
        std::cout << "Enter your phone number: ";
        std::cin >> customerPhoneNumber;
        customer->setPhoneNumber(customerPhoneNumber);
        std::cout << std::endl;
        if (Util::onlyNumbers(customerPhoneNumber) == 0)
        {
            throw PhoneNumberExc();
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Do you want to buy a book? ";
    std::cin >> purchaseConfirmation;
    std::cout << std::endl;

    if (purchaseConfirmation == "yes" || purchaseConfirmation == "YES" || purchaseConfirmation == "Yes")
    {
        do
        {
            outfile.open("transactions.txt", std::ios_base::app);
            std::cout << "Enter the book code of the book you want to buy: ";
            std::cin >> bookID;
            std::cout << std::endl;
            float bill = Book::buyBook(customerAge, bookID);
            std::cout << "The price of the book " << Book::getBookNameById(bookID) << " is " << bill << " RSD" << std::endl;

            std::cout << "Do you want to buy this book? " << std::endl;
            std::cin >> transactionConfirmation;
            if (transactionConfirmation == "yes" || transactionConfirmation == "Yes" || transactionConfirmation == "YES")
            {
                outfile << "Transaction number: " << transactionNumber << std::endl;
                outfile << "Customer: " << customer->getFirstName() << " " << customer->getLastName() << " " << customer->getAge() << " years, Phone Number: " << customer->getPhoneNumber() << std::endl;
                outfile << "Bought the book: " << Book::getBookNameById(bookID) << " for the price of " << bill << " RSD" << std::endl;
                outfile << "---------------------------------------------------------" << std::endl;
                transactionNumber++;
            }
            outfile.close();
            std::cout << "Do you want to continue shopping? ";
            std::cin >> continueShopping;
            std::cout << std::endl;
        } while (continueShopping == "yes" || continueShopping == "YES" || continueShopping == "Yes");
    }

    std::cout << "Do you want to review completed transactions?" << std::endl;
    std::cin >> transactionReview;
    std::cout << std::endl;

    if (transactionReview == "yes" || transactionReview == "YES" || transactionReview == "Yes")
    {
        infile.open("transactions.txt");
        if (infile.is_open())
        {
            std::string line;
            while (std::getline(infile, line))
            {
                std::cout << line << std::endl;
            }
            infile.close();
        }
        else
        {
            std::cout << "The file transactions.txt cannot be opened." << std::endl;
        }
    }

    return 0;
}