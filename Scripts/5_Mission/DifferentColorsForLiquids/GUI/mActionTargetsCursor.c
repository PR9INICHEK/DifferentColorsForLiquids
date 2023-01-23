modded class ActionTargetsCursor
{
	override protected void PrepareCursorContent()
	{
		super.PrepareCursorContent();
		
		// Добавляем пустую строку, чтобы отделить логи в этом файле от обычных
		Print("\n");
		// Добавляем отметку, в каком файле и методе мы сейчас находимся
		Print("ActionTargetsCursor::PrepareCursorContent() Called this method");

		ItemBase itemUnderCursor = ItemBase.Cast(m_Target.GetObject());
		if (itemUnderCursor)
			Print( "ActionTargetsCursor::PrepareCursorContent() itemUnderCursor: " + itemUnderCursor );
		if ( itemUnderCursor && itemUnderCursor.GetQuantity() > 0 && itemUnderCursor.IsLiquidContainer() )
		{
			int liquid_type = itemUnderCursor.GetLiquidType();
			
			if (liquid_type == LIQUID_GASOLINE || liquid_type == LIQUID_WATER)
			{
				Widget widget = m_Root.FindAnyWidget("item");
			
				// Ищем строку состояния
				ProgressBarWidget progressBar;
				Class.CastTo(progressBar, widget.FindAnyWidget("item_quantity_pb"));
				Print( "ActionTargetsCursor::PrepareCursorContent() progressBar: " + progressBar );
				
				// Получаем текущий цвет строки состояния
				Print( "ActionTargetsCursor::PrepareCursorContent() progressBar.GetColor(): " + progressBar.GetColor() );
				
				if ( liquid_type == LIQUID_GASOLINE )
					// Colors.ORANGE - https://www.htmlcsscolor.com/hex/FFA500
					progressBar.SetColor( ARGB( 255, 255, 165, 0 ) );
				// ??? TO DO Речная вода действительно существует
					// Похоже, что нет
				if ( liquid_type == LIQUID_WATER )
					// Colors.COLOR_LIQUID - https://www.htmlcsscolor.com/hex/0000FF
					//progressBar.SetColor( ARGB( 255, 0, 0, 255 ) );	// -16776961
					//progressBar.SetColor( Colors.COLOR_LIQUID );	// 61183
					//progressBar.SetColor( 16772608 );	// 
					// Подобрал с помощью Colour picker в гугле
					progressBar.SetColor( ARGB( 255, 0, 255, 255 ) );	// -16711681
			}
		}
		
		/*if ( m_Target.GetObject() && m_Target.GetObject().GetType() == "CanisterGasoline" )
		{
			// Код ниже есть и в ItemActionsWidget
				// TO DO Подумать, как его можно оптимизировать
			Widget widget = m_Root.FindAnyWidget("item");
			
			// Ищем строку состояния
			ProgressBarWidget progressBar;
			Class.CastTo(progressBar, widget.FindAnyWidget("item_quantity_pb"));
			
			//Print( "ActionTargetsCursor::PrepareCursorContent() progressBar: " + progressBar );
			
			// Получаем текущий цвет строки состояния
			//Print( "ActionTargetsCursor::PrepareCursorContent() progressBar.GetColor(): " + progressBar.GetColor() );
			
			// Если пустая канистра, то ничего не меняем
			//Print( "ActionTargetsCursor::PrepareCursorContent() q_cur: " + q_cur );
			
			// TO DO Перенести вызов GetItemQuantity() сюда, чтобы оптимизировать скрипт
			int q_type = 0;
			int q_min, q_max = -1;
			float q_cur = -1.0;
			
			// Вызываем этот метод, чтобы получить значение q_cur, которое будем использовать ниже
			GetItemQuantity(q_type, q_cur, q_min, q_max);
			// Если канистра начинает заполняться, то меняем цвет, в зависимости от жидкости
			if ( q_cur > 0)
			{
				//CanisterGasoline canisterGasoline;
				//Print( "ActionTargetsCursor::PrepareCursorContent() Class.CastTo( canisterGasoline, m_Target.GetObject() ): " + Class.CastTo( canisterGasoline, m_Target.GetObject() ) );
				
				CanisterGasoline canisterGasoline = CanisterGasoline.Cast( m_Target.GetObject() );
				
				if (canisterGasoline)
				{
				/*
				if ( Class.CastTo(canisterGasoline, m_Target) )
				{*/
					//Print( "ActionTargetsCursor::PrepareCursorContent() m_Target.GetObject(): " + m_Target.GetObject() );
				
					// TO DO Тут нужно унаследоваться от ItemBase
					//int liquid_type = m_Target.GetObject().GetLiquidType();
					
					/*int liquid_type = canisterGasoline.GetLiquidType();
					//Print( "ActionTargetsCursor::PrepareCursorContent() liquid_type: " + liquid_type );
					
					if ( liquid_type == LIQUID_GASOLINE )
						// Colors.ORANGE - https://www.htmlcsscolor.com/hex/FFA500
						progressBar.SetColor( ARGB( 255, 255, 165, 0 ) );
					// ??? TO DO Речная вода действительно существует
						// Похоже, что нет
					if ( liquid_type == LIQUID_WATER )
						// Colors.COLOR_LIQUID - https://www.htmlcsscolor.com/hex/0000FF
						//progressBar.SetColor( ARGB( 255, 0, 0, 255 ) );	// -16776961
						//progressBar.SetColor( Colors.COLOR_LIQUID );	// 61183
						//progressBar.SetColor( 16772608 );	// 
						// Подобрал с помощью Colour picker в гугле
						progressBar.SetColor( ARGB( 255, 0, 255, 255 ) );	// -16711681
				//}
				}
			}
			// Во всех остальных случаях сбрасываем на дефолтный
			else
			{
				progressBar.SetColor(-1);
			}
			
			
			// Как изначально
			// progressBar.SetColor(-1);
			// Проверяем, что всё поменялось
			//Print("\n");
			//Print( "ItemActionsWidget::BuildCursor() progressBar.GetColor(): " + progressBar.GetColor() );
			if ( q_cur > 0)
				//Print( "ItemActionsWidget::BuildCursor() progressBar.GetColor(): " + progressBar.GetColor() );
		}*/
	}

}