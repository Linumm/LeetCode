int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int maxWealth = 0;
    for (int i=0; i<accountsSize; i++){
        int eachAccSum = 0;
        for (int j=0; j<*accountsColSize; j++){
            eachAccSum += accounts[i][j];
        }
        if (eachAccSum >= maxWealth) maxWealth = eachAccSum;
    }

    return maxWealth;
}
//leethub test 1