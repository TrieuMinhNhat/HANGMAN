# <center>HANGMAN</center>

## Giới thiệu
- Đây là game HangMan (người treo cổ) - trò chơi đầu tiên do mình tạo ra.
- Hangman được biết đến là một tựa game dùng để học từ mới, đoán các câu mà được nạp sẵn trong một file văn bản.
- HangMan game là bài tập lớn trong môn lập trình nâng cao của mình
## Cách chơi
### Hangman có luật đơn giản, phù hợp với người chơi từ 6 tuổi
* Bạn chỉ cần nhấn play sau đó từ mà bạn phải đoán sẽ xuất hiện trên màn hình
* Bạn sẽ phải nhập lần lượt các chữ cái từ bàn phím dựa theo sự suy luận của bản thân
* Bạn chỉ có thể nhập sai tối đa 7 lần, nếu quá lỗi sai, bạn sẽ thua và chương trình sẽ tiết lộ từ bí mật.
* Sau khi kết thúc lượt chơi, bạn có thể lựa chọn chơi lại lần nữa hoặc thoát khỏi chương trình.
## Quá trình hoàn thành
Để làm được project này, mình đã tham khảo code mẫu hangman mà không có đồ họa, sau đó lên ý tưởng, tìm ảnh, chữ rồi chèn vào các hàm để chúng chạy theo trật tự logic. Mình cũng đã kết hợp thư viện SDL2, SDL_mixer, SDL_image và SDL_ttf để tạo thành một trò chơi có đồ họa 2D.
## Lý do làm HangMan
* Hangman game là một game hữu ích.

	Mặc dù khá nhàm chán, nhưng Hangman game rất phù hợp với những bạn muốn học thêm từ vựng. Ngoài Game còn có thể tích hợp vào việc giảng dạy trên lớp để học sinh có thể tìm ra từ bí mật, từ đó học sẽ nhớ được những từ mới nhanh hơn bằng một cách sinh động.
* Phù hợp với khả năng lập trình của bản thân	

	Cách thức hoạt động của game khá đơn giản. Mình đã được học và hiểu được toàn bộ logic của game trên trường, nên việc tạo ra nó cũng dễ dàng hơn. Hơn nữa, mình thấy tư duy và khả năng lập trình của mình còn khá yếu, nếu chọn game code khó và phức tạp để làm, khả năng không hoàn thiện sẽ rất cao.
## Kinh Nghiệm
*Sau khi hoàn thành hangman game, mình cũng rút ra được một số kinh nghiệm trong việc lập trình*
	Mình đã hiểu được cách thức hoạt động của một chương trình gồm nhiều file khác nhau. Muốn code dễ hiểu và dễ fix, mình nên chia nhỏ chương trình bằng cách chia file, viết hàm, comment code. Ngoài ra mình cũng đã hiểu và ứng dụng được một số kiến thức trên lớp vào game như Vector, Map, Struct,....

*Tóm lại, đây là một trải nghiệm đáng nhớ của mình, làm mình hứng thú hơn trong việc lập trình bởi việc tự tạo ra được một sản phẩm có ích mang lại cảm giác rất tự hào, mãn nguyện*
## Hướng dẫn
	Nếu bạn cảm thấy hứng thú hoặc muốn chơi thử trò chơi này có thể làm theo cách bước sau.
	1. Clone repo này về máy tính cá nhân.
	2. Tạo một solution và add tất cả các file trong **include** và **src** vào đó. Tải tất cả hình ảnh âm thanh, font vào chung file với solution.
	3. Cài SDL2 cho solution theo hướng dẫ tại [https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php].
	4. Run solution và chơi game thôi.
## Các nguồn đã tham khảo
		[https://lazyfoo.net/tutorials/SDL/index.php]
		[https://en.wikipedia.org/wiki/Simple_DirectMedia_Layer]
