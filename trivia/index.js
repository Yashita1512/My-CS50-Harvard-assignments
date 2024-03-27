let mcqButtons = document.querySelectorAll(".options button");

for (let i = 0; i < mcqButtons.length; i++){

    mcqButtons[i].addEventListener("click", function(){
        if (mcqButtons[i].innerHTML == "1 person per 3 sheep"){
            mcqButtons[i].style.backgroundColor = "green";
            document.querySelector(".options").before(" Correct! ");
        }
        else{
            mcqButtons[i].style.backgroundColor = "red";
            document.querySelector(".options").before(" Incorrect. ");
        }
    });
}

let freeCheckButton = document.querySelector(".free_response button");
let freeAnsField = document.querySelector(".free_response input");

freeCheckButton.addEventListener("click", function (){
    if (freeAnsField.value.toLowerCase() == "switzerland"){
        freeAnsField.style.backgroundColor = "green";
        document.querySelector(".free_response").before(" Correct! ");
    }
    else{
        freeAnsField.style.backgroundColor = "red";
        document.querySelector(".free_response").before(" Incorrect. ");
    }
});


