//
//  main.c
//  parabala
//
//  Created by Rufat Hajizada on 1/7/16.
//  Copyright © 2016 Rufat Hajizada. All rights reserved.
//

#include "parabala.h"
int main(void){
    char UserInput;
    float CoefA = 0.0, CoefB, CoefC, Discr, RootD;
    char UserChoice(void);
    float ScannerA(void);
    float ScannerB(void);
    float ScannerC(void);
    float Discrim(float CoefA, float CoefB, float CoefC);
    float RootDi(float Discr);
    void Solution(float CoefA, float CoefB, float RootD,float Discr,float CoefC);
    void Printer(float CoefA, float CoefB, float CoefC);
    UserInput = UserChoice();
    while (UserInput == 'y' || UserInput =='1'){
        printf("Print '54321' to stop the program\n");
        CoefA = ScannerA();
        if (CoefA == 54321){
            printf("Program ended\n");
            break;
        }
        CoefB = ScannerB();
        CoefC = ScannerC();
        if ( CoefA == 0){
            printf("Following equation is not quadratic\n");
        }
        else{
            Discr = Discrim(CoefA, CoefB, CoefC);
            RootD = RootDi(Discr);
            Printer(CoefA, CoefB, CoefC);
            Solution(CoefA, CoefB, RootD, Discr, CoefC);
        }
    }
    if (UserInput == 'n'){
        printf("Program ended\n");
    }
    return 0;
}
char UserChoice(void){
    char UserInput;
    printf("Welcome to parabala\nPrint 'y' or '1' to continue or 'n' to stop: ");
    UserInput = getchar();
    return UserInput;
}
float ScannerA(void){
    float coefA;
    printf("******************************************\nEnter coeficient A (STANDS BEFORE X^2): ");
    scanf("%f", &coefA);
    return coefA;
}
float ScannerB(void){
    float coefB;
    printf("Enter coeficient B (STANDS BEFORE X): ");
    scanf("%f", &coefB);
    return coefB;
}
float ScannerC(void){
    float coefC;
    printf("Enter coeficient C : ");
    scanf("%f", &coefC);
    return coefC;
}
float Discrim(float CoefA, float CoefB, float CoefC){
    float Discr;
    Discr = ( CoefB * CoefB ) - ( 4 * CoefA * CoefC );
    printf("Discriminant of equation is equal to %.2lf\n", Discr);
    return Discr;
}
float RootDi(float Discr){
    float RootD;
    RootD = sqrt(Discr);
    return RootD;
}
void Printer(float CoefA, float CoefB, float CoefC){
    printf("Function is ");
    if (CoefA == 1){
        printf("X^2+ ");
        printf("%.2f", CoefB);
        printf("X +");
        printf("%2.f = 0\n", CoefC);
    }
    else{
        printf("%.2f", CoefA);
        printf("X^2+ ");
        printf("%.2f", CoefB);
        printf("X +");
        printf("%2.f = 0\n", CoefC);
    }
}
void Solution(float CoefA, float CoefB, float RootD, float Discr, float CoefC){
    float X1, X2;
    float CoefA2;
    X1 = ( ( - CoefB - RootD ) / 2 * CoefA ) ;
    X2 = ( ( - CoefB + RootD ) / 2 * CoefA ) ;
    CoefA2 = CoefA * 2;
    printf ("Derivative of function is %.2f", CoefA2);
    printf("X + %.2f\n", CoefB);
    if (Discr == 0){
        printf ("This equation has only one solution which is %.2f\n", X1);
        printf("Discriminant of equation is equal to %.2f\n", Discr);
        printf ("Point of intersection of this function with OX axis is (%.2f, 0)\n", X1);
        printf("Point of intersection with OY axis is (0, %.2f)\n", CoefC);
    }
    else if ( Discr > 0){
        printf ("First solution of equation is %.2f\n", X1);
        printf ("Second solution of equation is %.2f\n", X2);
        printf("Discriminant of equation is equal to %.2f\n", Discr);
        printf ("Points of intersection of this function with OX axis are (%.2f, 0) and (%.2f, 0)\n", X1, X2);
        printf("Point of intersection with OY axis is (0, %.2f)\n", CoefC);
    }
    else{
        printf("This equation does not have solution");
        
    }
    
}

