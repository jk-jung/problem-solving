select
    id,
    COALESCE(NULLIF(name, ''), '[product name not found]') as name,
    price,
    COALESCE(NULLIF(card_name, ''), '[card name not found]') as card_name,
    card_number,
    transaction_date
from eusales
where price > 50∑