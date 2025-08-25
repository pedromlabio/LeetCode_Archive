bool checkSubstring(char *subString, int start, int end, int* size) {
    int counter[256] = {0};
    int sizeCounter = (end+1) - start; //for some logic reasons end value needs to be added here to work
    bool isValid = true;
    //printf("starting substring\n");
    for(int i = start; i <= end; i++){
        //printf("%c\n", subString[i]);
        counter[subString[i]]++;
    }
    for(int i = 0; i < 256; i++){
        if(counter[i] > 1){
            //printf("not valid");
            return false;
        }
    }
    if(sizeCounter > *size){
        *size = sizeCounter;
    }
    return true;
}



int lengthOfLongestSubstring(char* s) {
    bool isValid = false;
    int longest = 0;
    int len = strlen(s); //getting the size of the string
    for(int i = 0; i < len; i++){//looping in each char
        for(int j = i; j < len; j++){//second loop to get all substrings
            if(!checkSubstring(s, i, j, &longest)){
                //break
                break;
            }
        }
    }

    return longest;
}
