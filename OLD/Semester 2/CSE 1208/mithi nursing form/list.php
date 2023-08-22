<?php
$list_code = fopen("listCode.txt","r");
$list_inst = fopen("instructions.txt","r");
$final = fopen("Final Out.txt","w");
while(fgets($list_code,3)){
    while(fgets($list_inst,"\n")){
        if($list_code == $list_inst){
            fwrite($final,$list_inst);
        }
    }
}
fclose($list_code);
fclose($list_inst);
?>