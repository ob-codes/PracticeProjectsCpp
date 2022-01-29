int operate(int a, int b, char oper)
{
    int result;
    switch (oper)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    case '%':
        result = a % b;
        break;
    default:
        break;
    }
    return result;
}