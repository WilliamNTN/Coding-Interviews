//Your friend is typing his name into a keyboard.  Sometimes, when typing a character c
//the key might get long pressed, and the character will be typed 1 or more times.

//You examine the typed characters of the keyboard.  Return True if it is possible that
//it was your friends name, with some characters (possibly none) being long pressed.

class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        int pName = 0, pTyped = 0;
        
        while(pName < name.size() && pTyped < typed.size()){
            if(name[pName] == typed[pTyped]){
                pName++; pTyped++;
            }
            else{
                if(pName > 0 && typed[pTyped] == name[pName-1]){
                    pTyped++;
                }
                else{
                    return false;
                }
            }
        }
        
        if(pName < name.size()) return false;
        while(pTyped < typed.size()){
            if(typed[pTyped] != name[name.size()-1]) return false;
            pTyped++;
        }
        
        return true;
    }
};