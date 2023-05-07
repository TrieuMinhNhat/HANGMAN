Đây là game hangman (người treo cổ) - trò chơi đầu tiên do mình tạo ra.

Hangman được biết đến là một tựa game dùng để học từ mới, đoán các câu mà được nạp sẵn trong một file văn bản.

Cách chơi Hangman rất đơn giản, bạn chỉ cần nhấn play sau đó từ mà bạn phải đoán sẽ xuất hiện trên màn hình. Bạn sẽ phải nhập lần lượt các chữ cái từ bàn phím dựa theo sự suy luận của bản thân. Bạn chỉ có thể nhập sai tối đa 7 lần. Nếu quá lỗi sai, bạn sẽ thua và chương trình sẽ tiết lộ từ bí mật. Sau khi kết thúc lượt chơi, bạn có thể lựa chọn chơi lại lần nữa hoặc thoát khỏi chương trình.

Để làm được project này, mình đã tham khảo code mẫu hangman mà không có đồ họa, sau đó lên ý tưởng, tìm ảnh, chữ rồi chèn vào các hàm để chúng chạy theo trật tự logic. Mình cũng đã kết hợp thư viện SDL2, SDL_mixer (liên quan đến Load âm thanh), SDL_image (những thứ liên quan đến Load hình ảnh), SDL_ttf (những thứ liên quan đến Load chữ).

Có một số lý do mình lựa chọn code game này. Mặc dù khá nhàm chán, nhưng Hangman game rất phù hợp với những bạn muốn học thêm từ vựng. Game còn có thể tích hợp vào việc giảng dạy trên lớp để học sinh có thể tìm ra từ bí mật, từ đó người chơi sẽ nhớ được những từ mới. Hơn nữa, cách thức hoạt động của game khá đơn giản. Mình đã được học và hiểu được toàn bộ logic của game, nên việc tạo ra nó cũng dễ dàng hơn. Cuối cùng, mình thấy tư duy và khả năng lập trình của mình còn khá yếu, nếu chọn game khó và phức tạp để làm, khả năng không hoàn thiện được sẽ rất cao.

Sau khi hoàn thành hangman game, mình cũng rút ra được một số kinh nghiệm trong việc lập trình. Đầu tiên, mình đã hiểu được cách thức hoạt động của một chương trình gồm nhiều file khác nhau. Muốn code dễ hiểu và dễ fix, mình nên chia nhỏ chương trình bằng cách chia file, viết hàm, comment code. Ngoài ra mình cũng đã hiểu và ứng dụng được một số kiến thức trên lớp vào game như Vector, Map, Struct,....

Tóm lại, đây là một trải nghiệm đáng nhớ của mình, làm mình hứng thú hơn trong việc lập trình bởi việc tự tạo ra được một trò chơi đem lại cảm giác rất tự hào, mãn nguyện
