#include <iostream>
#include <torch/torch.h>

int main()
{
    // pro CPU
    //torch::Tensor x = torch::randn({ 3,3 });
    // pro GPU
    torch::Tensor x = torch::randn({3,3}, torch::kCUDA);
    std::cout << x;
}