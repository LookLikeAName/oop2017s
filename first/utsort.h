#ifndef UTSORT_H_INCLUDED
#define UTSORT_H_INCLUDED

void swap (int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void bubble (int a[], int s, bool (*comp) (int, int)){
    for(int j = 1; j <= s-1; j++){
        for (int i = s-1; i>=j; i--){
            if (comp(a[i],a[i-1])) //call the function
                swap(a[i],a[i-1]);
        }
    }
}


bool lessThan(int a, int b){
    return a < b;
}

TEST (Bubble, increasing){
    int a[5]= {5,2,43,6,9};
    bubble (a, 5, lessThan);

    ASSERT_EQ(2, a[0]);
    ASSERT_EQ(5, a[1]);
    ASSERT_EQ(6, a[2]);
    ASSERT_EQ(9, a[3]);
    ASSERT_EQ(43, a[4]);
}


bool greaterThan(int a, int b){
    return a > b;
}

TEST (Bubble, decreasingFunction){
    int a[5]= {5,2,43,6,9};
    bubble(a, 5, greaterThan);

    ASSERT_EQ(43, a[0]);
    ASSERT_EQ(9, a[1]);
    ASSERT_EQ(6, a[2]);
    ASSERT_EQ(5, a[3]);
    ASSERT_EQ(2, a[4]);
}
#endif // UTSORT_H_INCLUDED
