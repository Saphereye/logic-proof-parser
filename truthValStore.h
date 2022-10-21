#include <string>
using namespace std;

/**
 * @brief Contains parameters and methods for calculating the truth value of the propositional logic formula in task 5
 * 
 */
class TruthValStore {
    private:
        string _atomArray = "";
        size_t _truthValArray = 0b0; 
        
    public:
        TruthValStore() {

        }

        /**
         * @brief Construct a new Truth Val Store object(using two parameters)
         * 
         * @param atomArray It contains the string of propositional atoms only
         * @param truthValArray It contains the corresponding truth values
         */
        
        TruthValStore(string atomArray, int truthValArray) {
            _atomArray = atomArray;
            _truthValArray = truthValArray;
        }

        /**
        * @brief Construct a new Truth Val store object(using one parameter)
         * 
         * @param atomArray It contains the string of propositional atoms only
         * 
         */
        TruthValStore(string atomArray) {
                _atomArray = atomArray;
            }

        /**
         * @brief Set the Atom Array object
         * 
         * @param atomArray It contains the string of propositional atoms only
         */
        void setAtomArray(string atomArray) {
            _atomArray = atomArray;
        }

        /**
         * @brief Get the Atom Array object
         * 
         * @return String of propositional atoms
         */
        string getAtomArray() {
            return _atomArray;
        }

        /**
         * @brief Get the truth value of corresoponding atom in O(n)
         * 
         * @param atom Propositional atom
         * @return true 
         * @return false 
         */
        bool getTruthVal(char atom) {
            /** @brief Get index of atom in atom array*/ 
            size_t index = _atomArray.find(atom);

            /** @brief All cases where atom is not present
             */

            /** @brief Return the nth element of truthValArray from the right where n = index
            */ 
            
            return (_truthValArray & (1 << index)) >> index;
        }

        /**
         * @brief Set the truth value of corresoponding atom in O(n)
         * 
         * @param atom Propositional atom
         * @param truthVal Truth value of propositional atom
         * @return true 
         * @return false 
         */
        void setTruthVal(char atom, bool truthVal) {
            // Get index of atom in array
            size_t index = _atomArray.find(atom);

            // Make mask to help replace
            size_t mask = 1 << index;

            // Set value in truthValArray using bitwise magic
            _truthValArray = (_truthValArray & ~mask) | ((truthVal << index) & mask);
        }
    

        void setTruthVal(size_t index, bool truthVal) {
            // Make mask to help replace
            size_t mask = 1 << index;

            // Set value in truthValArray using bitwise magic
            _truthValArray = (_truthValArray & ~mask) | ((truthVal << index) & mask);

            debug("Index to setter", index);
            debug("truth val array to setter", _truthValArray);
        }
        
        /**
        * @brief Function to add propositional atom to the string
        * @param atom Propositional atom
        */
        void addAtom(char atom) {
            _atomArray += atom;
        }
        
        /**
        * @brief Function to find propositional atom at required index in the string
        * @param size_t index 
        */
        char getAtom(size_t index) {
            return _atomArray[index];
        }

        size_t getTruthValArray() {
            return _truthValArray;
        }

        size_t getAtomIndex(char atom) {
            return _atomArray.find(atom);
        }
};
