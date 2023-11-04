#include <string>
#include <stdio.h>

namespace Controller
{

    class Bluetooth
    {
    public:
        Bluetooth() {}
        ~Bluetooth() {}

        void InitBluetoothController()
        {
            printf("Initializing bluetooth controller.\n");
        }

    private:
        std::string _bt_type;
    };
};