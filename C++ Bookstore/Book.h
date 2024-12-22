#pragma once
#include "Author.h"
#include <iostream>
#include <string>
#include <vector>

class Book
{
private:
    std::string id;
    std::string bookName;
    Author& author;
    float price;
    int stockCount;

public:
    Book(const std::string id, const std::string bookName, Author& author, float price, int stockCount)
        : id(id), bookName(bookName), author(author), price(price), stockCount(stockCount) {}

    void setId(std::string id) {
        this->id = id;
    }
    std::string getId() {
        return this->id = id;
    }

    void setBookName(std::string bookName) {
        this->bookName = bookName;
    }
    std::string getBookName() {
        return this->bookName = bookName;
    }

    void setAuthor(Author& author) {
        this->author = author;
    }
    Author& getAuthor() {
        return this->author = author;
    }

    void setPrice(float price) {
        this->price = price;
    }
    float getPrice() {
        return this->price = price;
    }

    void setStockCount(int stockCount) {
        this->stockCount = stockCount;
    }
    int getStockCount() {
        return this->stockCount = stockCount;
    }

    static std::vector<std::unique_ptr<Book>> bookList;

    static void addBook(std::unique_ptr<Book> book) {
        bookList.push_back(std::move(book));
    }

    static void printBookList() {
        for (const auto& book : bookList) {
            std::cout << *book << std::endl;
        }
    }

    static std::string getBookNameById(const std::string& id) {
        for (const auto& book : bookList) {
            if (book->getId() == id)
            {
                return book->getBookName();
            }
        }
    }

    static float buyBook(int age, const std::string& id);

    friend std::ostream& operator<<(std::ostream& out, const Book& b);

    ~Book() {}
};
