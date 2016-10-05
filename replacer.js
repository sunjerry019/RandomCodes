$("#content p").each(function(){
	x = $(this).html();
	x = x.replace(/Ae/g, "Ä");
	x = x.replace(/Oe/g, "Ö");
	x = x.replace(/Ue/g, "Ü");
	x = x.replace(/ae/g, "ä");
	x = x.replace(/oe/g, "ö");
	x = x.replace(/ue/g, "ü");
	$(this).html(x);
});