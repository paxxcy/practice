char* reverseString(char* s) {
    int i;
    int n;
    int mid;
    char* c;

    //find the length of the string
    //for(n=0;(*s)!='\0';n++);
    n=0;
    while(*(s+n)!='\0')
        n++;

    //define the midpoint of the string
    mid = n/2;

    //reverse the string
    for(i=0;i<mid;i++){
        //swap
        c = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = c;
    }

    return s;
}
