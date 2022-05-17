//******* E-Agricultor Projeto Integrador 2022 *********

function show_nav(){
    var box_nav = document.getElementById("navbarNavDropdown");
    if(box_nav.classList[2] == "show"){
        box_nav.classList.remove("show");
    }
    else{
        box_nav.classList.add("show");
    }
}