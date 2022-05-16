/**
 * file: proj4-ItemInfo.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: project 4
 * due date: 2/28/2022
 *
 * date modified:  2/24/2022
 *    - functions defined:
 *          - setItemId
 *          - setDescription
 *
 * date modified:  2/25/2022
 *    - functions defined:
 *          - setManCost
 *          - setSellPrice
 *          - getItemId
 *          - *getDescription
 *          - getManCost
 *          - getSellPrice
 *          - stuCstrToDbl
 *          - setManCost
 *          - setSellPrice
 *
 * date modified:  2/26/2022
 *    - functions defined:
 *          - stuCstrCpy
 *          - stuCstrLen
 *
 * date modified:  2/27/2022
 *    - functions defined:
 *          - toAmazonJSON
 *          - displayItemInfo
 *          - stuCstrToDbl
 *          - stuDblToCstr
 *          - printCString
 *
 * This file defines functions within the "proj4-ItemInfo.hpp".
 */

#include "proj4-ItemInfo.hpp"

void ItemInfo::setItemId(const char *num) {
    this->itemId = 0;
    for (int i = 0; num[i] != '\0'; i++) {
        this->itemId *= 10;
        this->itemId += num[i] - '0';
    }
}

void ItemInfo::setDescription(const char *cstr) {
    int i = 0;
    while (cstr[i] != 0) {
        this->description[i] = cstr[i];
        i++;
    }
    this->description[i] = '\0';
}

void ItemInfo::setManCost(const char *num) {
    this->manCost = stuCstrToDbl(num);
}

void ItemInfo::setSellPrice(const char *num) {
    this->sellPrice = stuCstrToDbl(num);
}

int ItemInfo::getItemId() {
    return this->itemId;
}

const char *ItemInfo::getDescription() {
    return this->description;
}

double ItemInfo::getManCost() {
    return this->manCost;
}

double ItemInfo::getSellPrice() {
    return this->sellPrice;
}

void ItemInfo::toAmazonJSON(ostream &out) {
    char* temp = new char [40];
    printCString(out, "\t\t\"itemId\": ");
    stuDblToCstr(temp, this->itemId);
    printCString(out, temp);
    printCString(out, ",\n");

    printCString(out, "\t\t\"description\": ");
    printCString(out, this->description);
    printCString(out, ",\n");

    printCString(out, "\t\t\"manPrice\": ");
    stuDblToCstr(temp, this->manCost);
    printCString(out, temp);
    printCString(out, ",\n");


    printCString(out, "\t\t\"sellPrice\": ");
    stuDblToCstr(temp, this->sellPrice);
    printCString(out, temp);
    out.put('\n');
    delete [] temp;
}

void ItemInfo::displayItemInfo(ostream &out) {
    //Prints: "itemID: [itemId #]"
    printCString(out, "itemID: ");
    char* ID = new char [6];
    int decimalIndex = 0;
    if (this->itemId == 0) {
        ID[0] = '0';
        ID[1] = '\0';
    }
    else {
        stuDblToCstr(ID, static_cast<double>(this->itemId));
        while (ID[decimalIndex] != '.') {
            decimalIndex++;
        }
        ID[decimalIndex] = '\0';
    }
    printCString(out, ID);
    out.put('\n');

    //Prints: "description: [desc]"
    printCString(out, "description: ");
    char *desc = new char [40];
    stuCstrCpy(desc, this->description);
    printCString(out, desc);
    out.put('\n');
    delete [] desc;

    //Prints: "manCost: [manCost]"
    printCString(out, "manCost: ");
    char* mCost = new char [10];
    stuDblToCstr(mCost, this->manCost);
    printCString(out, mCost);
    out.put('\n');
    delete [] mCost;

    //Prints: "sellPrice: [sellPrice]"
    printCString(out, "sellPrice: ");
    char* sPrice = new char [10];
    stuDblToCstr(sPrice, this->sellPrice);
    printCString(out, sPrice);
    out.put('\n');
    delete [] sPrice;

    //Prints: "calculatedProfit: [profit]"
    printCString(out, "calculatedProfit: ");
    char* profit = new char [10];
    double profitNum = calcProfit();
    stuDblToCstr(profit, profitNum);
    printCString(out, profit);
    out.put('\n');
    delete [] profit;
}

double ItemInfo::calcProfit() {
    return this->sellPrice - this->manCost;
}

double stuCstrToDbl(const char *num) {
    double dbl = 0;
    double numPlace = 10;
    double temp;
    int i = 0;
    bool afterDecimal = false;

    while (num[i] != '\0') {
        if (num[i] == '.') {
            afterDecimal = true;
            numPlace = 0.1;
            i++;
        }
        else if (afterDecimal) {
            temp = num[i] - '0';
            temp *= numPlace;
            dbl += temp;
            numPlace /= 10;
            i++;
        }
        else {
            dbl *= numPlace;
            dbl += num[i] - '0';
            i++;
        }
    }
    return dbl;
}

void stuDblToCstr(char *cstr, double num) {
    if (num == 0) {
        cstr[0] = '0';
        cstr[1] = '.';
        cstr[2] = '0';
        cstr[3] = '0';
        cstr[4] = '\0';
    }
    else {
        double dbl = num;
        int findCount = static_cast<int>(num);
        int countBeforeDecimal = 0;
        int countAfterDecimal;
        int temp, digit;

        while (findCount >= 1) {
            findCount /= 10;
            countBeforeDecimal++;
        }
        cstr[countBeforeDecimal] = '.';
        countAfterDecimal = countBeforeDecimal + 1;

        while (dbl >= 1.0) {
            temp = static_cast<int>(dbl);
            digit = temp % 10;
            cstr[countBeforeDecimal - 1] = '0' + digit;
            dbl -= digit;
            dbl /= 10;
            countBeforeDecimal--;
        }
        for (int i = 0; i < countAfterDecimal - 1; i++) {
            dbl *= 10;
        }
        for (int i = 0; i < 2 && dbl != 0.0; i++) {
            dbl *= 10;
            temp = static_cast<int>(dbl);
            cstr[countAfterDecimal] = '0' + temp;
            dbl -= temp;
            countAfterDecimal++;
        }
        cstr[countAfterDecimal] = '\0';
    }
}

void stuCstrCpy(char *dest, const char *src) {
    int i;
    if (dest != src) {
        //Checks to see if the destination is empty
        if (stuCstrLen(dest) > 0) {
            delete [] dest;
            dest = new char [stuCstrLen(src)];
        }

        for (i = 0; src[i] != '\0'; i++) {
            dest[i] = src[i];
        }
        dest[i] = '\0';
    }
}

int stuCstrLen(const char *src) {
    int count = 0;
    while (src[count] != '\0') {
        count++;
    }
    return count;
}

ostream& printCString(ostream &out, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        out.put(src[i]);
        i++;
    }
    return out;
}