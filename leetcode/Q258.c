int addDigits(int num) {
    if(num<10) return num;
    int n=0;
    
    while(num>0){
        n = n + (num%10);  //n += num%10;
        num = num / 10; //num /= 10;
    }
    return addDigits(n);
}
