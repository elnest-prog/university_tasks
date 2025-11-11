
var swiper = new Swiper(".thisSwiper", {
  spaceBetween: 30,
  pagination: {
      el: ".swiper-pagination",
  },
  mousewhell: true,
  keyboard: true, 
  slidesPerView: 'auto',
  breakpoints: {
      576: {
        slidesPerView: 2,
        spaceBetween: 20,
      },
      768: {
        slidesPerView: 3,
        spaceBetween: 20,
      },
      1200: {
          slidesPerView: 4,
          spaceBetween: 20,
        },
    }
});  