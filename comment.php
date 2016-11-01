<?php


function getCommentInfo($keyword, $openid)
{
    if(isset($_SERVER['HTTP_APPNAME'])){        //SAE
        $mysql_host = SAE_MYSQL_HOST_M;
        $mysql_host_s = SAE_MYSQL_HOST_S;
        $mysql_port = SAE_MYSQL_PORT;
        $mysql_user = SAE_MYSQL_USER;
        $mysql_password = SAE_MYSQL_PASS;
        $mysql_database = SAE_MYSQL_DB;
    }else{
        $mysql_host = "127.0.0.1";
        $mysql_host_s = "127.0.0.1";
        $mysql_port = "3306";
        $mysql_user = "root";
        $mysql_password = "root";
        $mysql_database = "weixin";
    }
	
	$mysql_table = "CommentInfo";
	//$id = rand(1, 33);
    
    //$keyword1 = substr($keyword, strpos($keyword, " ")+1);
	
	
    //$mysql_state = "SELECT * FROM `".$mysql_table."` WHERE `keyword` like '%".$keyword1."%'";
    //search admin

    //$mysql_state = "SELECT * FROM `".$mysql_table;
    $mysql_state = "INSERT INTO `".$mysql_table." values(NULL, '".$openid."', '".$keyword."')";
    $con = mysql_connect($mysql_host.':'.$mysql_port, $mysql_user, $mysql_password);
	if (!$con){
		die('Could not connect: ' . mysql_error());
	}
	
	mysql_query("SET NAMES 'UTF8'");
	mysql_select_db($mysql_database, $con);
	$result = mysql_query($mysql_state);

	$cinfo = "";
    $index=1;
    if($result == false)
        $cinfo = "留言失败，请再次输入\n";
    else{    
        /*while($row = mysql_fetch_array($result)){
		  /*$cinfo[]  = array("Title" =>$row["keyword"], "Description" =>"", "PicUrl" =>"http://d.hiphotos.bdimg.com/wisegame/pic/item/f3529822720e0cf3ac9f1ada0846f21fbe09aaa3.jpg", "Url" =>$row["url"]);*/
        //$cinfo = "第".$index."条留言: ".$row["comment"].""
        $cinfo = "留言成功\n";
    }
    mysql_close($con);
	return $cinfo;
}
    
?>