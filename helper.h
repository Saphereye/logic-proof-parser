#include <iostream>
#include <string>

// This all is linux specific!!
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

using namespace std;

bool isDebugMode = false;

/**
 * @brief Prints debug info
 * 
 * @tparam T 
 * @param comment 
 * @param data 
 */
template <typename T>
inline void debug(string comment, T data) {
	if (isDebugMode) cout << BLUE << "[DEBUG!] " << comment << " : " << data << RESET << endl;
}

/**
 * @brief Prints out comments/trace info
 * 
 * @param comment 
 */
inline void trace(string comment) {
	if (isDebugMode) cout << GREEN << "[TRACE!] " <<  comment << RESET << endl;
}

/**
 * @brief Prints out any todo comments
 * 
 * @param comment 
 */
inline void todo(string comment) {
    if (isDebugMode) cout << YELLOW << "[TODO!!] " <<  comment << RESET << endl;
}

inline void error(string comment) {
    // throw invalid_argument("[ERROR!] " + comment);
    if (isDebugMode) cerr << RED << "[ERROR!] " <<  comment << RESET << endl;
}

template <typename T>
inline void error(string comment, T data) {
	//throw invalid_argument("[ERROR!] " + comment + " : " + data);
    if (isDebugMode) cerr << RED << "[ERROR!] " <<  comment << " : " << data << RESET << endl;
}

inline void clearScreen() {
    cout << "\033[2J\033[1;1H";
}
