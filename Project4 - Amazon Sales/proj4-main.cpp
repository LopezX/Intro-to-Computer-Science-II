/**
 * file: proj4-ItemInfo.hpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: project 4
 * due date: 2/28/2022
 *
 * date modified:  2/24/2022
 *    - file created
 *
 * date modified:  2/28/2022
 *    - main was created
 *
 *
 * This is the main for the project.
 */

#include "proj4-ItemInfo.hpp"
#include <fstream>

/**
 * checkForIncrementation
 *
 * This function checks to see if ItemInfo array should be incremented
 *
 * Parameters:
 *      a: ItemInfo pointer array
 *      c: holds the array of ItemInfo objects
 *      s: the size of the ItemInfo array
 *
 * Output:
 *      return: bool
 *      reference parameters: none
 *      stream: none
 */
bool checkForIncrementation(int, int);

/**
 * profitSort
 *
 * This function sorts the ItemInfo array by profit
 *
 * Parameters:
 *      a: ItemInfo pointer array
 *      s: the size of the ItemInfo array
 *
 * Output:
 *      return: void
 *      reference parameters: sorts a by profit (most to least)
 *      stream: none
 */
void profitSort(ItemInfo *, int);

int main() {
    //Creates an ItemInfo Array
    int count = 0, size = 2;
    ItemInfo *products = new ItemInfo [size];
    ifstream inputFile;
    char* buffer = new char [500];
    char* data = new char [40];
    char c;
    int i, j, k, whereToStore;

    inputFile.open("proj4-productServices.csv");

    //Checks to see if file opened
    if (!inputFile) {
        cout.write("No file found.", 14);
        cout.put('\n');
    }
    else {
        while (!inputFile.eof()) {
            i = 0;
            j = 0;
            k = 0;
            whereToStore = 0;

            //Reads a line of code
            while (inputFile.get(c) && c != '\n'){
                buffer[i] = c;
                i++;
            }
            buffer[i] = ',';

            //Checks to see if incrementation is needed
            if (checkForIncrementation(count, size)) {
                ItemInfo *temp = new ItemInfo [size];
                char *tempCstr = new char [40];
                for (int l = 0; l < size; l++) {
                    stuDblToCstr(tempCstr, products[l].getItemId());
                    tempCstr[5] = '\0';
                    temp[l].setItemId(tempCstr);
                    temp[l].setDescription(products[l].getDescription());
                    stuDblToCstr(tempCstr, products[l].getManCost());
                    temp[l].setManCost(tempCstr);
                    stuDblToCstr(tempCstr, products[l].getSellPrice());
                    temp[l].setSellPrice(tempCstr);
                }
                delete [] products;
                size += 2;
                products = new ItemInfo [size];
                for (int l = 0; l < size - 2; l++) {
                    stuDblToCstr(tempCstr, temp[l].getItemId());
                    tempCstr[5] = '\0';
                    products[l].setItemId(tempCstr);
                    products[l].setDescription(temp[l].getDescription());
                    stuDblToCstr(tempCstr, temp[l].getManCost());
                    products[l].setManCost(tempCstr);
                    stuDblToCstr(tempCstr, temp[l].getSellPrice());
                    products[l].setSellPrice(tempCstr);
                }
                delete [] temp;
                delete [] tempCstr;
            }

            //Reads each data and allocates to its specific memory
            if (buffer[0] != ',') {
                while (j <= i) {
                    if (buffer[j] != ',') {
                        data[k] = buffer[j];
                        k++;
                    }
                    else {
                        data[k] = '\0';
                        if (whereToStore == 0) {
                            products[count].setItemId(data);
                            whereToStore++;
                        }
                        else if (whereToStore == 1) {
                            products[count].setDescription(data);
                            whereToStore++;
                        }
                        else if (whereToStore == 2) {
                            products[count].setManCost(data);
                            whereToStore++;
                        }
                        else {
                            products[count].setSellPrice(data);
                        }
                        k = 0;
                    }
                    j++;
                }
                count++;
            }
        }
    }

    //Sort array by profit
    profitSort(products, size);

    printCString(cout, "\"X-man\'s Emporium\": [\n");
    for (int l = 0; l < count && l < 5; l++) {
        if (l == 0) {
            cout.put('\t');
            printCString(cout, "\"firstItem\": {\n");
        }
        else if (l == 1) {
            cout.put('\t');
            printCString(cout, "\"secondItem\": {\n");
        }
        else if (l == 2) {
            cout.put('\t');
            printCString(cout, "\"thirdItem\": {\n");
        }
        else if (l == 3) {
            cout.put('\t');
            printCString(cout, "\"fourthItem\": {\n");
        }
        else {
            cout.put('\t');
            printCString(cout, "\"fifthItem\": {\n");
        }

        products[l].toAmazonJSON(cout);

        if (l <= 3) {
            printCString(cout, "\t},\n");
        }
        else {

            printCString(cout, "\t}\n");
        }
    }
    printCString(cout, "]\n");

    delete [] products;
    delete [] buffer;
    delete [] data;
    inputFile.close();
    return 0;
}

bool checkForIncrementation(int c, int s) {
    return (c + 1) > s;
}

void profitSort(ItemInfo *a, int s) {
    ItemInfo temp;
    for (int i = 0; i < s - 1; i++) {
        for (int j = 0; j < s - 1 - i; j++) {
            if (a[j].calcProfit() < a[j+1].calcProfit()) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}