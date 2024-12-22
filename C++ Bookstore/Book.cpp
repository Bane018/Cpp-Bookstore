#include "Book.h"
#include<iostream>
#include<string>
#include<ostream>

std::ostream& operator<<(std::ostream& out, const Book& b)
{
    out << "Book ID: " << b.id << ", Book Name: " << b.bookName << ", Author: " << b.author << ", Price: " << b.price << " EUR" << ", Stock Count: " << b.stockCount << std::endl;
    return out;
}

float Book::buyBook(int age, const std::string& id)
{
    float bookPrice = 0.0;

    for (auto& book : bookList) {
        if (book->getId() == id) {
            bookPrice = book->getPrice();

            if (age <= 16) {
                bookPrice *= 0.7;
            }
            else if (age >= 17 && age <= 24) {
                bookPrice *= 0.9;
            }
            else if (age >= 25 && age <= 30) {
                bookPrice *= 0.95;
            }

            int stockCount = book->getStockCount();
            if (stockCount > 0) {
                book->setStockCount(stockCount - 1);
            }

            break;
        }
    }

    return bookPrice;
}
