//Testcases: https://hr-testcases-us-east-1.s3.amazonaws.com/15305/input03.txt?AWSAccessKeyId=AKIAJ4WZFDFQTZRGO3QA&Expires=1594904704&Signature=WBEjJucMPnV1BUO1MKvpzEH79NM%3D&response-content-type=text%2Fplain
//Testcases solutions: https://hr-testcases-us-east-1.s3.amazonaws.com/15305/output03.txt?AWSAccessKeyId=AKIAJ4WZFDFQTZRGO3QA&Expires=1594904716&Signature=oNhX1DmoH6AO3xRFglkYUzCtVCM%3D&response-content-type=text%2Fplain

#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.


long merge(vector<int>& arr,int temp[], int start, int mid, int end)
{
    int ver = 0;
    int i, j, k;
    i=start;
    j=mid+1;
    k=start;
    
    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            
            ver+=(mid-i+1);
        }
    }

    while(i<=mid)
        temp[k++]  =arr[i++];
    while(j<=end)
        temp[k++] = arr[j++];
    
    for(i=start; i<=end; i++)
    {
        // cout<<"\narr["<<i<<"] = "<<arr[i]<<" temp["<<i<<"] = "<<temp[i]<<endl;
        arr[i] = temp[i];
    }

    return ver;
}


long mergesort(vector<int>& arr, int temp[], int start, int end)
{
    long ver=0;
    if(start<end)
    {
        ver += mergesort(arr, temp, start, (start+end)/2);
        ver += mergesort(arr, temp, (start+end)/2+1, end);
        
        ver += merge(arr, temp, start, (start+end)/2, end);
    }
    return ver;
}

void minimumBribes(vector<int> q) {
    int n = q.size();




    int bribes[n] = {0};
    for(int i=0; i<n; i++)
    {
        bribes[i] = abs(q[i]-(i+1));
        if(bribes[i]>2 && (q[i]-i)>3)
        {
            cout<<"Too chaotic"<<endl;
            return;
        }
    }





    // cout<<"\nThe bribes array:"<<endl;
    // for(int i=0; i<n; i++)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(int i=0; i<n; i++)
    // {
    //     cout<<bribes[i]<<" ";
    // }
    // cout<<endl;
    int temp[n];
    cout<<mergesort(q, temp, 0, n-1);

}


// void minimumBribes(vector<int> q) {
//     int n = q.size();
//     cout<<"\n"<<n;
//     int bribes[n] = {0};
//     for(int i=0; i<n; i++)
//     {
//         bribes[i] = abs(q[i]-(i+1));
//         if(bribes[i]>2)
//         {
//             cout<<"Too chaotic"<<endl;
//             return;
//         }
//     }

//     for(int i=0; i<n; i++)
//     {
//         cout<<"\n"<<bribes[i];
//     }
//     for(auto i:q)
//     {
//         cout<<"\n"<<i;
//     }

// }

int main()
{
    auto start = high_resolution_clock::now();

    vector<int> q;
    string str = "3 1 5 2 7 6 4 9 12 8 11 10 14 13 16 17 15 18 20 23 19 21 27 22 24 25 30 26 28 29 34 31 32 33 36 35 38 37 39 42 41 40 43 44 45 47 46 49 50 48 51 53 56 52 55 54 59 57 58 60 63 62 61 65 64 68 66 67 72 70 71 69 73 77 74 76 78 79 75 80 83 82 81 84 86 85 89 91 87 88 90 93 92 96 95 94 97 99 98 101 100 102 104 105 103 108 106 107 111 112 109 114 110 115 113 117 120 116 118 122 119 121 126 123 124 129 127 130 125 128 135 131 132 133 136 134 138 137 139 141 140 145 142 143 148 146 144 147 150 151 149 152 155 153 154 157 156 159 161 158 160 163 164 162 166 165 167 168 170 169 171 175 174 173 172 176 178 177 179 180 183 181 182 184 189 186 185 190 187 191 195 188 192 193 196 194 198 201 197 200 199 202 203 204 209 207 206 205 208 211 210 212 214 213 215 216 218 217 220 219 222 221 224 223 225 226 230 228 227 231 229 234 233 232 238 235 239 236 241 237 242 240 244 245 243 247 246 249 248 251 250 252 253 254 255 259 256 258 257 261 263 260 262 264 267 266 265 269 268 272 270 273 271 275 276 274 279 277 278 281 283 280 282 288 284 285 287 286 292 290 289 291 293 295 294 296 299 298 297 302 303 300 301 305 307 306 310 304 308 309 313 311 314 312 315 318 317 320 316 319 323 322 326 321 324 325 329 328 327 331 330 333 335 332 336 339 334 338 337 341 340 345 343 342 346 344 348 347 349 350 351 354 353 355 352 357 356 359 362 361 358 366 360 364 365 363 369 368 367 370 371 372 373 374 375 378 377 379 376 380 382 383 381 384 386 385 391 388 387 390 389 392 395 397 396 394 393 398 399 402 401 400 405 404 406 403 407 410 409 408 412 414 411 413 415 418 417 416 419 420 422 421 423 425 424 426 427 428 430 429 434 431 435 432 433 437 436 439 438 441 440 444 442 443 445 449 447 446 448 453 451 452 450 457 455 456 454 461 459 464 460 462 463 458 468 465 466 469 471 470 474 467 472 473 477 475 476 480 483 479 478 482 481 487 486 484 485 489 488 491 490 493 492 496 494 495 498 499 500 497 503 501 504 502 506 507 505 509 508 510 512 513 511 514 516 520 515 519 517 523 522 521 518 525 524 526 527 530 529 528 532 531 533 538 534 535 536 540 537 539 542 541 543 545 544 547 550 548 546 553 551 552 549 554 556 555 557 559 558 562 560 563 561 566 564 565 568 569 567 570 572 574 573 571 576 575 578 577 580 579 584 581 582 583 585 587 589 586 592 591 590 588 594 593 598 595 596 602 597 599 601 603 600 605 604 606 608 607 609 610 613 611 612 614 615 617 619 616 620 618 621 623 622 625 626 628 624 629 633 627 630 635 632 631 634 637 636 641 640 642 638 644 639 646 645 643 651 648 650 647 649 653 654 657 656 655 652 660 659 658 662 661 665 663 666 664 667 669 671 668 670 672 676 673 675 674 678 677 680 683 681 679 684 682 685 686 687 688 690 689 693 691 696 692 695 694 700 697 698 702 701 699 704 703 705 707 706 708 709 711 712 710 714 713 716 715 718 717 720 719 725 722 721 724 723 727 731 726 728 730 729 733 736 734 735 732 738 739 737 741 742 740 743 745 744 749 747 748 746 751 750 753 752 754 756 755 760 758 762 757 761 764 763 759 765 768 766 770 769 767 773 772 774 776 777 771 775 780 778 781 779 783 782 784 790 785 787 789 786 792 788 791 794 796 795 793 797 801 800 799 802 798 804 808 805 803 807 806 809 812 810 811 813 815 814 817 818 820 816 819 823 822 825 821 827 826 824 829 832 828 830 831 835 833 836 834 838 837 839 843 840 841 846 845 842 847 844 849 851 848 854 850 853 855 852 858 856 859 857 860 861 866 862 864 863 865 868 873 867 869 871 870 876 874 872 875 878 877 879 883 880 881 885 882 886 884 887 888 889 892 890 891 893 894 895 897 896 900 902 901 899 898 904 906 905 903 908 911 910 907 909 913 912 916 917 915 914 920 918 919 922 921 923 925 924 926 928 930 927 929 931 932 933 938 939 934 935 936 940 937 942 943 941 945 944 946 949 950 948 947 954 953 951 955 958 952 960 956 957 961 959 964 962 967 963 965 966 968 970 969 972 971 975 974 977 976 973 980 978 979 982 981 983 985 984 991 986 988 987 992 989 993 996 994 990 997 995 ";
    int length = str.size();
    string sub = "";
    for(int i=0; i<length; i++)
    {
        if(str[i]!=' ')
        {
            sub = sub + str[i];
            // cout<<sub<<endl;
        }
        else
        {
            // cout<<sub<<endl;
            q.push_back(std::stoi(sub));
            sub = "";
        }
        
    }
    // vector<int> q{1,2,5,3,7,8,6,4};

    minimumBribes(q);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}