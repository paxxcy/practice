char* frequencySort(char* s) {
    int i,j,k;
    int freqSize=(int)'~'+2;
    
    //get the string length
    int len = strlen(s);
    //create frequency array
    int* freq = (int*)malloc(sizeof(int)*freqSize);
    for(i=0;i<freqSize;i++) freq[i] = 0;
    //create ret
    char* ret = (char*)malloc(sizeof(char)*len+1);
    for(i=0;i<len+1;i++) ret[i] = '\0';
    //char ret[len+1] = {'\0'};
    
    //run once to get frequency
    int max = 0,curr;
    for(i=0;i<len;i++){
        //increment
        curr = ++freq[s[i]];
        //get max
        max = curr>max ? curr : max;
    }
    //start printing
    int pos = 0;
    for(i=max;i>=1;i--){ //go through all values - i.e. selection sort O(n^2)
        for(j=(int)' ';j<=(int)'~';j++){
            if(freq[j]==i){
                //print this character i times
                for(k=0;k<i;k++){
                    //printf("%c",(char)j);
                    ret[pos++] = (char)j;
                }
            }
        }
    }
    
    //free and return
    free(freq);
    return ret;
}
