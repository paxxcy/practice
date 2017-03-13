char* reverseVowels(char* s){
    int i;
    int n;
    int mid;
    char* c;
    int* vowels;
    int vowelCount;
    
    //find the length of the string
    n=0;
    while(*(s+n)!='\0')
        n++;

    //find the vowels
    vowelCount=0;
    vowels = (int*) malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            //it's a vowel
            vowels[vowelCount++] = i;
        }
    }
    
    //define the midpoint of the number of vowels
    mid = vowelCount/2;

    //reverse the string
    for(i=0;i<mid;i++){
        //swap
        c = s[vowels[i]];
        s[vowels[i]] = s[vowels[vowelCount-i-1]];
        s[vowels[vowelCount-i-1]] = c;
    }
    
    free(vowels);
    
    return s;
}
