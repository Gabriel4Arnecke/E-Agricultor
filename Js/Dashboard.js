const side_nav = document.getElementById('side_bar')
const main_content = document.getElementById('main')
const height_windows = window.innerHeight;
const height_footer = document.getElementById('footer').clientHeight;

window.addEventListener("load", function(event) { // Steps para o inicio da página

  // Consertando tamanho da side bar com relação ao tamanha da tela de cada despositivo
  console.log(height_windows - height_footer);
  side_nav.style.height = height_windows - height_footer + "px";

  // Adjust Width for content main
  main_content.style.marginLeft = 100 - ((window.innerWidth - side_nav.clientWidth) * 100/ window.innerWidth) + "%"
});

// Arrow to do hide/show side bar
const span_home = document.getElementById('home')
const span_dash = document.getElementById('dash')
const arrow_less = document.getElementById('less')
const arrow_more = document.getElementById('more')
const logo_info = document.getElementById('logo_info')
const name_user_info = document.getElementById('name_user_info')
const fixed_size_side = (side_nav.clientWidth * 100/ window.innerWidth) 

function less(){
  // Controle de visores
  span_dash.style.display = 'none'
  span_home.style.display = 'none'
  arrow_more.style.display = 'block'
  arrow_less.style.display = 'none'        
  logo_info.style.display = 'none'
  name_user_info.style.display = 'none'
  // Ajuste do Width side bar
  side_nav.style.width = (fixed_size_side * 0.25) + '%'
  arrow_more.style.marginLeft = '50%'
  main_content.style.marginLeft = 100 - ((window.innerWidth - side_nav.clientWidth) * 100/ window.innerWidth) + "%"
}
function more(){
  // Controle de visores
  span_dash.style.display = 'inline'
  span_home.style.display = 'inline'
  arrow_more.style.display = 'none'
  arrow_less.style.display = 'block'
  logo_info.style.display = 'block'
  name_user_info.style.display = 'block'
  // Ajuste do Width side bar
  side_nav.style.width = fixed_size_side + '%'
  main_content.style.marginLeft = 100 - ((window.innerWidth - side_nav.clientWidth) * 100/ window.innerWidth) + "%"        
}