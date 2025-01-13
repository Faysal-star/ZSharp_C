// Import another Z# file
slidein "math.zh"
// Define a class
clout Calculator levelUp BaseCalc {
    lowkey bet result = 0
    highkey era add(x, y) {
        bet sum = x + y
        yeet sum
    }
    highkey era multiply(x, y) {
        bet product = x * y
        yeet product
    }
}

// Function declarations
era test_add(x, y) {
    bet isum = x + y
    yeet isum
}

// Main function
era OG() {
    // Function call
    bet func_sum = test_add(1, 3)
    spill_tea func_sum
    
    // Variables and constants
    bet counter = 0
    bet str = "Hello, World!"
    spill_tea str
    spill_tea str[0]

    // Constants
    fr PI = 3.14159
    
    // Array
    squad numberss = [1, 2, 3, 4, 5]
    spill_tea numberss[0]
    spill_tea numberss[1]
    
    // If-else statement
    vibeCheck (counter == 0) {
        spill_tea "Starting the program"
        vibeCheck (counter == 1) {
            spill_tea "Counter is 1"
        }
        meh {
            spill_tea "Counter is not 0 or 1"
        }
    } aint (counter < 0) {
        spill_tea "Negative counter"
    } meh {
        spill_tea "Positive counter"
    }
    
    // Loop
    loopin(bet i = 0 # i < 5 # i = i + 1) {
        vibeCheck (i == 2) {
            ghost
        }
        spill_tea i
        loopin( bet ii = 0 # ii < 5 # ) {
            spill_tea ii
            ii = ii + 1
        }
        
    }

    
    // Try-catch block
    test {
        bet yy = 10 / 0
    } caughtIn4k(e) {
        spill_tea "Caught division by zero!"
    }

    // precedence check
    counter = 2 + 6 / (3 * 2 ) * 2
    
    yeet 0
}