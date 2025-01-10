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
        test {
            bet product = x * y
            yeet product
        } caughtIn4k {
            spill_tea "Error in multiplication"
            yeet 0
        }
    }
}
// Main function
era OG() {
    // Variables and constants
    bet counter = 0
    bet str = "Hello, World!"
    fr PI = 3.14159
    // Array
    squad numbers = [1, 2, 3, 4, 5]
    // If-else statement
    vibeCheck (counter == 0) {
        spill_tea "Starting the program"
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
        spill_tea `Current number is ${numbers[i]}`
    }


    
    // Try-catch block
    test {
        bet yy = 10 / 1
    } caughtIn4k {
        spill_tea "Caught division by zero!"
    }

    counter = 2 + 6 / 3 * 2 / 2
    
    yeet 0
}