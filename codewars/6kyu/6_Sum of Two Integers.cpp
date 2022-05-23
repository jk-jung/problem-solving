int Add (int a, int b)
{
    if(b == 0) return a;
    return Add(a ^ b, (a & b) << 1);
}