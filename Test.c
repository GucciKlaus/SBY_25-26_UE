int foo (int a, int b, int c)
{
	int local=42;
	local++;
	return a+b+c+local;
}

int main(int argc, char** argv)
{
	return foo(1,2,3);
}
