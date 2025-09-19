class Spreadsheet {
public:
    unordered_set<char> set ;
    vector<vector<int>> sheet ;
    Spreadsheet(int rows){
        sheet.assign(rows,vector<int>(26,0)) ;
       for(int i = 1 ; i <= 26 ;i++){
            set.insert(char(64 + i)) ;
       }
    }
    
    void setCell(string cell, int value) {
        int indexCol = (int)cell[0] - 65 ;
        int n = cell.length() ;
        int i = 1 ;
        int indexRow  = 0 ;
        while(i < n){
         int    y = (int)cell[i++] - (int)'0' ;
         indexRow = indexRow*10 + y ;
        }
        indexRow -= 1 ;

        sheet[indexRow][indexCol] = value ;
    }
    
    void resetCell(string cell) {

        int indexCol = (int)cell[0] - 65 ;
        int n = cell.length() ;
        int i = 1 ;
        int indexRow  = 0 ;
        while(i < n){
              int  y = (int)cell[i++] - (int)'0' ;
              indexRow = indexRow*10 + y ;
        }
        indexRow -= 1 ;

        sheet[indexRow][indexCol] = 0 ;
        
    }
    
    int getValue(string formula) {
        int n = formula.length() ;
        int a ;int b ;
        int i = 1 ;
        if(set.find(formula[i]) != set.end()){
        int indexCol = (int)formula[i++] - 65 ;
        
        int indexRow  = 0 ;
        while(i < n && formula[i] != '+'){
         int    y = (int)formula[i++] - (int)'0' ;
         indexRow = indexRow*10 + y ;
        }
        indexRow -= 1 ;

         a = sheet[indexRow][indexCol]  ;

        }else{

           
            int indexRow  = 0 ;
             while(i < n && formula[i] != '+'){
                  int y = (int)formula[i++] - (int)'0' ;
                   indexRow = indexRow*10 + y ;
        }
              a = indexRow ;

        }

        if(formula[i] == '+'){
            i = i+1 ;
        }

         if(set.find(formula[i]) != set.end()){
        int indexCol = (int)formula[i] - 65 ;
         i = i+1;
        int indexRow  = 0 ;
        while(i < n && formula[i] != '+'){
         int    y = (int)formula[i++] - (int)'0' ;
         indexRow = indexRow*10 + y ;
        }
        indexRow -= 1 ;

         b = sheet[indexRow][indexCol]  ;

        }else{

             
            int indexRow  = 0 ;
             while(i < n && formula[i] != '+'){
                  int y = (int)formula[i++] - (int)'0' ;
                   indexRow = indexRow*10 + y ;
        }
              b = indexRow ;

        }


        return a + b ;

    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */