
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <random>

using namespace std;

/// The RandomNumberGenerator class is a wrapper around the Standard C++
/// Library's Mersenne Twister pseudo random number generator.
/// This class is complete and correct; please do not make any changes to it.
///
/// In lieu of directly working with the [Mersenne Twister
/// class]
/// (https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine),
/// this class serves as a lightweight wrapper around the necessary elements of
/// the library. The usage of this class is very simple and requires a
/// minimum and maximum value for initialization.
/// \code
/// int minimum_random_number = 1;
/// int maximum_random_number = 10;
/// RandomNumberGenerator my_random_number_generator{minimum_random_number,
/// maximum_random_number}; int random_number =
/// my_random_number_generator.next();
/// \endcode
class RandomNumberGenerator {
 private:
  /// A hardware entropy source (a device on your computer to give random bits)
  std::random_device rd;
  /// A sequence of random bits to seed the Mersenne Twister engine
  std::seed_seq seed;
  /// A Mersenne Twister engine
  std::mt19937 mt_engine;
  /// A uniform distribution; select numbers randomly in a uniform manner
  std::uniform_int_distribution<> uniform_dist;

 public:
  /// Constructor to the RandomNumberGenerator class
  ///
  /// The RandomNumberGenerator generates random integer numbers between
  /// \p minimum and \p maximum. The constructor initializes and prepares
  /// the engine. To generate a number use the <RandomNumberGenerator::next>()
  /// method.
  ///
  /// \param minimum The lowest value the random number generator will return
  /// \param maximum The largest value the random number generator will return
  RandomNumberGenerator(int minimum, int maximum)
      : seed{rd()}, mt_engine{rd()}, uniform_dist{minimum, maximum} {}

  /// Return a random number
  ///
  /// Returns a random integer number between the minimum and maximum set
  /// when the constructor was called.
  /// \sa RandomNumberGenerator::RandomNumberGenerator
  ///
  /// \returns An integer between the minimum and maximum set when
  /// the constructor was called
  auto next() -> int {
    int random_number = uniform_dist(mt_engine);
    // std::cout << "Debugging: The random number is " << random_number << "\n";
    return random_number;
  }
};

/// ErrorMessage prints out \p message first and then prints the standard
/// message
/// \code
/// "There was an error. Exiting.\n".
/// \endcode
///
/// \param message The programmer defined string that specifies the current
/// error.
void ErrorMessage(const string& message) {
  cout << message << "\n";
  cout << "There was an error. Exiting.\n";
}

/// PrintVector prints out the elements of \p the_vector each on a line of
/// their own.
///
/// This function uses
/// [copy()](https://en.cppreference.com/w/cpp/algorithm/copy) and
/// an
/// [ostream_iterator()]
/// (https://en.cppreference.com/w/cpp/iterator/ostream_iterator)
/// to copy each element of \p the_vector to cout.
///
/// \code
/// vector<int> the_vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
/// PrintVector(the_vector);
/// \endcode
///
/// This above code will print:
/// \code
/// 1
/// 2
/// 3
/// 4
/// 5
/// 6
/// 7
/// 8
/// 9
/// 10
/// \endcode
///
/// \param the_vector This is the vector of integers created in
/// the main function.
void PrintVector(const vector<int>& the_vector) {
  // TODO: print out each element in the vector using an ostream_iterator
}

/// FillVector filles \p the_vector with \p nelements random numbers given by
/// \p random_number_generator.
///
/// Using [generate()](https://en.cppreference.com/w/cpp/algorithm/generate),
/// \p the_vector is filled with values that are returned by the next()
/// method of \p random_number_generator.
///
/// \param the_vector The vector of integers created in the main function.
/// \param nelements The number of random numbers to generate and insert
/// into \p the_vector.
/// \param random_number_generator The random number generator created in
/// the main function.
/// \sa RandomNumberGenerator::next()
/// \remarks This function uses a [C++ Lambda Expression]
/// (https://en.cppreference.com/w/cpp/language/lambda)
/// as the third parameter to generate.
void FillVector(vector<int>& the_vector, const int nelements,
                RandomNumberGenerator& random_number_generator) {
  // TODO: assign a random number to each location in the vector using
  // generate() from the C++ standard library.

}

/// CalculateAverage calculates the average (arithmetic mean) of all the
/// values stored in \p the_vector. _Must be done using C++ Standard
/// Library functions._
///
/// The algorithm starts by delcaring and initializing an integer variable
/// which will represent the sum of all the values in \p the_vector. Using
/// [accumulate()](https://en.cppreference.com/w/cpp/algorithm/accumulate)
/// sum the elements of \p the_vector and store the result into an integer
/// variable.
///
/// Calculate the average by promoting the sum and the size of \p the_vector
/// to floats and find the quotient.
///
/// \f[\bar{x} = \frac{1}{n}\sum_{i = 1}^{n} x_i\f]
///
/// \param the_vector The vector of integers created in the main function.
///
/// \returns The average (arithmetic mean) value in the vector as a float
float CalculateAverage(const vector<int>& the_vector) {
  return -42.0
}

/// Entry point to the calc_average_plusplus program
/// \remark Must have at least 3 arguments. The first argument is the minimum
/// number generated by the random number generator, the second argument
/// is the maximum number generated by the random number generator, and
/// the third argument is how many elements to insert into the vector.
int main(int argc, char* argv[]) {
  if (argc < 4) {
    ErrorMessage(
        "Please provide two positive integers as the maximum and "
        "minimum for this exercise and the number of integers to "
        "generate.");
    exit(1);
  }
  string argv_one_minimum = string(argv[1]);
  string argv_two_maximum = string(argv[2]);
  string argv_three_number_elements = string(argv[3]);
  int minimum_number = 0;
  int maximum_number = 0;
  int number_elements = 0;
  try {
    minimum_number = stoi(argv_one_minimum);
  } catch (const exception& e) {
    ErrorMessage("Trouble converting the first argument to a number.");
    exit(1);
  }

  try {
    maximum_number = stoi(argv_two_maximum);
  } catch (const exception& e) {
    ErrorMessage("Trouble converting the second argument to a number.");
    exit(1);
  }

  try {
    number_elements = stoi(argv_three_number_elements);
  } catch (const exception& e) {
    ErrorMessage("Trouble converting the third argument to a number.");
    exit(1);
  }

  if (maximum_number <= minimum_number || maximum_number < 0 ||
      minimum_number < 0) {
    ErrorMessage(
        "Please make sure your first number is less than your second "
        "number and that they are both positive integers.");
    exit(1);
  }

  RandomNumberGenerator rng(minimum_number, maximum_number);
  vector<int> random_numbers(number_elements);
  
  // Fill the vector with random numbers between min and max
  FillVector(random_numbers, number_elements, rng);
  // Print the vector, one element on each line
  PrintVector(random_numbers);
  // Find the average value
  float average = CalculateAverage(random_numbers);
  // Print out the average value
  cout << "The average value of the vector is " << average << "\n";
  return 0;
}
