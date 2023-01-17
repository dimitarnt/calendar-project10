/**
*
* Solution to course project # 10
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Dimitar Nikolaev Tankov
* @idnumber 2MI0600229
* @compiler GCC
*
* <header file with math functions>
*
*/

int pow(int n, int k){
    int result = 1;
    int n1 = n;
    for(int i = 0; i < k; ++i){
        result = n;
        n *= n1;
    }

    return result;
}
