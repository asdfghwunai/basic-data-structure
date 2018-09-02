1.普通二分查找

int BinarySearch(int array[], int n, int value)
{
    int left = 0;
    int right = n - 1;
    //如果这里是int right = n 的话，那么下面有两处地方需要修改，以保证一一对应：
    //1、下面循环的条件则是while(left < right)
    //2、循环内当 array[middle] > value 的时候，right = mid

    while (left <= right)  //循环条件，适时而变
    {
        int middle = left + ((right - left) >> 1);  //防止溢出，移位也更高效。同时，每次循环都需要更新。
        if (array[middle] > value)
            right = middle - 1;  //right赋值，适时而变
        else if (array[middle] < value)
            left = middle + 1;
        else
            return middle;
        //可能会有读者认为刚开始时就要判断相等，但毕竟数组中不相等的情况更多
        //如果每次循环都判断一下是否相等，将耗费时间
    }
    return -1;
}
//---------------------------------

2.查找第一次出现的下标
int BinarySearch(int array[], int n, int value)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)  
    {
        int middle = left + ((right - left) >> 1);
        if (array[middle] >= value)  //因为是找到最小的等值下标，所以等于号放在这里
            right = middle - 1;
        else
            left = middle + 1;
    }
    return array[right + 1] == value ? right + 1 : -1;   //right比left小， right位置的数肯定是<mid的
}

//--------------------------------
3.查找最后一次出现的下标
int BinarySearch(int array[], int n, int value)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)  
    {
        int middle = left + ((right - left) >> 1);
        if (array[middle] > value)  //因为是找到最大的等值下标，所以等于号放在这里
            right = middle - 1;
        else
            left = middle + 1;
    }
    return array[left - 1] == value ? left - 1 : -1;   //left是超right的，left的值肯定大于value
}

//--------------------
4.给定一个有序的数组，查找最接近value且大于value的数的下标（如果该数存在多个，返回第一个下标），不存在返回-1。

int BinarySearch(int array[], int n, int value)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)  
    {
        int middle = left + ((right - left) >> 1);
        if (array[middle] > value)   //此处让right出来时小于等于value
            right = middle - 1;
        else
            left = middle + 1;
    }
    return array[right + 1] > value ? right + 1 : -1;    //出来时right是比left小的，并且right位置的数必小于value
}

//--------------------------------------
5.查找最接近value且小于value的数的下标（如果该数存在多个，返回最后一个下标）呢？

int BinarySearch(int array[], int n, int value)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)  
    {
        int middle = left + ((right - left) >> 1);
        if (array[middle] >= value)                 
            right = middle - 1;
        else                            //出来循环时left肯定大于等于value
            left = middle + 1;
    }
    return array[left-1] < value ? left - 1 : -1;
}
